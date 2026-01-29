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

#ifndef PAUSE_PLAY_H
#define PAUSE_PLAY_H

typedef enum playState_t {
    OUT_OF_BOUNDS = -1,
    OFF = 0,
    ON = 1,
} PlayState;

#define PAUSE_PLAY_GPIO 27
#define PAUSE_PLAY_ADC 1

void init_pause_play(void);

void configure_pause_play_control(void);

PlayState read_state(void);

#endif /* PAUSE_PLAY_H */