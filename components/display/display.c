/*******************************************************************
 *
 * File Name: display.c
 *
 * Description:
 *   controller for the screen that displays songs and playlist options.
 *
 * Author: sparrow
 * Date: 18/1/26
 *
 * Assumptions:
 *   using a 4 pin led display
 *
 *******************************************************************/

#include "display.h"

#include <stdio.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

// TODO: pull song from spotify or file system

void configure_display(void) {
    // config pins for display
}

void switch_mode(Mode mode) {
    // switch mode: playlists <-> songs
    switch (mode) {
        case SONGS:
            // switch to songs tab
            // TODO: implementations
            break;
        case PLAYLISTS:
            // switch to playlists tab
            // TODO: implementation
            // NOTE: fsdfsdf
            break;
        default:
            printf("you're using the wrong enum");
            break;
    }
}

void switch_song(Command command) {
    // switch song: prev <-> next
    switch (command) {
        case PREV:
            // switch to previous song
            // TODO: implementation
            break;
        case NEXT:
            // switch to next song
            // TODO: implementation
            break;
        default:
            printf("you're using the wrong enum");
            break;
    }
}

void render(Mode page) {
    printf("On page: %d\n", page);
}
