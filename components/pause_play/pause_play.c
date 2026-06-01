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

#define sleep_duration 10  // milliseconds

void init_pause_play() {
    adc_gpio_init(PAUSE_PLAY_GPIO);  // GPIO27 corresponds to ADC1
}

play_state_t read_state() {
    adc_select_input(PAUSE_PLAY_ADC);  // Select ADC1
    sleep(10);                         // stablise ADC
    sleep_ms(sleep_duration);          // Wait for ADC to stabilize
    // Return current level as on/off/out_of_bounds
    // == 1 / 0 / -1

    int raw = adc_read();
    // convert to % of 100

    if (raw > (RAW_ADC_BOUNDS)OVER) {
        // if over 50% == out_of_bounds
        return OUT_OF_BOUNDS;
    } else if (raw > (RAW_ADC_BOUNDS)GOOD) {
        // if over 25% == ON
        return ON;
    } else {
        return OFF;
    }
}