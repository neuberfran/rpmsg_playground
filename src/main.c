#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/ipc/ipc_service.h>
#include <zephyr/shell/shell.h>
#include <string.h>

LOG_MODULE_REGISTER(host, LOG_LEVEL_INF);

struct payload {
   unsigned long size;
   char command_string[64];
};

static struct payload remote_command;
static struct payload remote_reply;
static const struct device *ipc0_instance = DEVICE_DT_GET(DT_NODELABEL(ipc0));

static K_SEM_DEFINE(bound_sem, 0, 1);

static void ep_bound (void *priv) 
{
   k_sem_give (&bound_sem);
}

static void ep_recv(const void *data, size_t len, void *priv)
{
    memcpy(&remote_reply, data, len);
    k_sem_give (&bound_sem);
}

static struct ipc_ept_cfg ep_cfg = {  
    .name = "ep0",
    .cb = {
        .bound = ep_bound,
        .received = ep_recv,
    }, 
};

int main(void)
{
    struct ipc_ept ep; 
    int ret;

    ret = ipc_service_open_instance(ipc0_instance);
    if ((ret < 0) && (ret != -EALREADY)) {
       LOG_INF("ipc_service_open_instance() failure");
       return ret;
    }

    ret = ipc_service_register_endpoint(ipc0_instance, &ep, &ep_cfg);
    if (ret < 0) {
        LOG_INF("ipc_service_register_endpoint() failure"); 
        return ret;
    }

    k_sem_take(&bound_sem, K_FOREVER); 
    LOG_INF("ipc service is ready to communicate!");

    strcpy(remote_command.command_string, "AT+IPC_COMMAND\n\r");
    remote_command.size = strlen(remote_command.command_string) + 1;

    while(1) {
        ret = ipc_service_send(&ep, &remote_command, sizeof(remote_command)); 
        LOG_INF("sending AT command: %s to remote CPU", remote_command.command_string);
         
        if (ret == -ENOMEM) { 
           /* No space in the buffer. Retry. */
            LOG_WRN("No space in the vring buffer retrying...");
            continue;
         }

         k_sem_take(&bound_sem, K_FOREVER);
         LOG_INF("received from remote CPU the response: %s", remote_reply.command_string);
         k_sleep(K_MSEC(1000));
      }
      return 0;
   }



    



