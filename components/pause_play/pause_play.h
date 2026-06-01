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

#pragma once

typedef enum play_state {
    OUT_OF_BOUNDS = -1,
    OFF = 0,
    ON = 1,
} play_state_t;

typedef enum RAW_ADC_BOUNDS {
    OVER = 3500,
    GOOD = 2000,
} RAW_ADC_BOUNDS;

#define PAUSE_PLAY_GPIO 27
#define PAUSE_PLAY_ADC 1

void init_pause_play(void);

/**
 * @brief Read the raw ADC value of the play_state potentiometer and returns an enum with the state.
 *
 * @return play_state_t: result of current adc position
 */
play_state_t read_state(void);
