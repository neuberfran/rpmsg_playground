#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/peripheral@50000000/clock@5000:
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_clock_5000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 2 : /soc/peripheral@50000000/gpio@842800:
 * Supported:
 *    - /soc/peripheral@50000000/spi@c000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_gpio_842800[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 8, DEVICE_HANDLE_ENDS };

/* 3 : /soc/peripheral@50000000/gpio@842500:
 * Supported:
 *    - /sensor-pwr-ctrl
 *    - /soc/peripheral@50000000/spi@c000
 *    - /regulator-3v3-ctrl
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_gpio_842500[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 9, 8, 10, DEVICE_HANDLE_ENDS };

/* 4 : /soc/peripheral@50000000/uart@8000:
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_uart_8000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /ipc/ipc0:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/mbox@2a000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_ipc_S_ipc0[] = { 7, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/peripheral@50000000/i2c@9000:
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_i2c_9000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/peripheral@50000000/mbox@2a000:
 * Supported:
 *    - /ipc/ipc0
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_mbox_2a000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 5, DEVICE_HANDLE_ENDS };

/* 8 : /soc/peripheral@50000000/spi@c000:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/gpio@842800
 *    - /soc/peripheral@50000000/gpio@842500
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_peripheral_50000000_S_spi_c000[] = { 2, 3, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 9 : /sensor-pwr-ctrl:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/gpio@842500
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_sensor_pwr_ctrl[] = { 3, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 10 : /regulator-3v3-ctrl:
 * Direct Dependencies:
 *    - /soc/peripheral@50000000/gpio@842500
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_regulator_3v3_ctrl[] = { 3, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
