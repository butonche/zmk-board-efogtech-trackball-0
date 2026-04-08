/*
 * Drop zero-value input events to prevent extra HID reports.
 * The dual-sensor mixer emits WHEEL events with value 0 every cycle,
 * which cause the central to send redundant HID reports that clear
 * the movement state.
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/input/input.h>
#include <drivers/input_processor.h>

static int drop_zero_handle_event(const struct device *dev,
                                  struct input_event *event,
                                  uint32_t param1, uint32_t param2,
                                  struct zmk_input_processor_state *state) {
    if (event->value == 0) {
        return ZMK_INPUT_PROC_STOP;
    }
    return ZMK_INPUT_PROC_CONTINUE;
}

static struct zmk_input_processor_driver_api drop_zero_api = {
    .handle_event = drop_zero_handle_event,
};

#define DT_DRV_COMPAT zmk_input_processor_drop_zero

#define DZ_INST(n) \
    DEVICE_DT_INST_DEFINE(n, NULL, NULL, NULL, NULL, \
                          POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, \
                          &drop_zero_api);

DT_INST_FOREACH_STATUS_OKAY(DZ_INST)
