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
     k_sem_give(&bound_sem);
}

static void ep_recv(const void *data, size_t len, void *priv)
{ 
    memcpy(&remote_command, data, len);
    k_sem_give(&bound_sem);
}
static struct ipc_ept_cfg ep_cfg = {
    .name = "ep0", 
    .cb = {
         .bound    = ep_bound,
         .received = ep_recv,
    },
};

int main(void)
{
    struct ipc_ept ep;
    int ret;

    ret = ipc_service_open_instance(ipc0_instance);
    if ((ret < 0) && (ret != -EALREADY)) {
        return ret;
    }
    
    ret = ipc_service_register_endpoint (ipc0_instance, &ep, &ep_cfg);

    if (ret < 0) {
        return ret;
    }

    k_sem_take(&bound_sem, K_FOREVER);

    while(1) {
        k_sem_take(&bound_sem, K_FOREVER);
        strcpy(remote_reply.command_string, "OK, REMOTE CPU IS LIVE\n\r");
        remote_reply.size = strlen(remote_reply.command_string) + 1;
        ipc_service_send(&ep, &remote_reply, sizeof(remote_reply));
    }
        return 0;
}