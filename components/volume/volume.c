/*******************************************************************
 *
 * File Name: volume.c
 *
 * Description:
 *   Implements volume control functionality for a music control device.
 *   Provides functions to adjust volume levels and retrieve current levels.
 *
 * Author: sparrow
 * Date: 16/01/26
 *
 *******************************************************************/

#include "volume.h"

#include <stdbool.h>
#include <stdio.h>

#include "hardware/adc.h"
#include "pico/stdlib.h"

void init_volume(void) {
    adc_gpio_init(VOLUME_GPIO);  // GPIO26 corresponds to ADC0
}

void configure_volume_control(void) {
    adc_select_input(VOLUME_ADC);  // Select ADC0
    sleep_ms(10);                  // Wait for ADC to stabilize
    // Initialize volume control settings
}

int read_volume_raw(bool print_voltage) {
    // Read raw ADC value for volume control
    // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
    int result = adc_read();
    const float conversion_factor = 3.3f / (1 << 12);
    if (print_voltage) {
        printf("Raw value: 0x%03x, val voltage: %f V\n", result, result * conversion_factor);
    }
    // value as a percentage
    return result;
}

int read_volume_percent(void) {
    // Return current volume level as a percentage
    int result = adc_read();
    // convert to % of 100
    int percent = (result * 100) / 4095;
    return percent;
    // float percentage = ((result * 100.0f) / 2047.5f) - 100.0f;
    // round with casting trick to avoid banker's rounding
    // int rounded_percentage = (int)(percentage + 0.5);
    // return rounded_percentage;
}
