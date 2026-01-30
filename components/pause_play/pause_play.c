/*******************************************************************
 *
 * File Name: pause_play.c
 *
 * Description:
 *   Implements pause/play functionality for the music control device.
 *   Provides funtions to read on/off/out_of_bounds
 *
 * Author: sparrow
 * Date: 26/1/26
 *
 *******************************************************************/

#include "pause_play.h"

// #include <stdbool.h>
#include <stdio.h>

#include "hardware/adc.h"
#include "pico/stdlib.h"

void init_pause_play(void) {
    adc_gpio_init(PAUSE_PLAY_GPIO);  // GPIO27 corresponds to ADC1
}

void configure_pause_play_control(void) {
    adc_select_input(PAUSE_PLAY_ADC);  // Select ADC1
    sleep_ms(10);                      // Wait for ADC to stabilize
}

PlayState read_state(void) {
    // Return current level as on/off/out_of_bounds
    // == 1 / 0 / -1
    int raw = adc_read();
    // convert to % of 100

    if (raw > 3500) {
        // if over 50% == out_of_bounds
        return OUT_OF_BOUNDS;
    } else if (raw > 2000) {
        // if over 25% == ON
        return ON;
    } else {
        return OFF;
    }
}