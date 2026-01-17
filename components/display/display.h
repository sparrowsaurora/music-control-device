/*******************************************************************
 *
 * File Name: display.h
 *
 * Description:
 *   Header file for:
 *   controller for the screen that displays songs and playlist options.
 *
 * Author: sparrow
 * Date: 18/1/26
 *
 * Assumptions:
 *   using a 4 pin led display
 *
 *******************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

typedef enum Command_t {
    PREV,
    NEXT
} Command;

typedef enum Mode_t {
    SONGS,
    PLAYLISTS
} Mode;

void configure_display(void);

void switch_mode(Mode mode);

void switch_song(Command command);

void render(Mode page);  // ?

#endif /* DISPLAY_H */