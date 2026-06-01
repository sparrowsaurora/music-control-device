#include <stdio.h>

#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

// components
#include "display.h"
#include "pause_play.h"
#include "volume.h"

/**
 * get & display volume compnent reading
 */
void read_volume() {
    int volume_percentage = read_volume_percent();
    printf("Volume: %%%d\n", volume_percentage);
}

/**
 * get & display pause/play state
 */
void read_play_state() {
    play_state_t state = read_state();
    if (state == OUT_OF_BOUNDS) {
        // error noti here
        // force continuation
        printf("STATE: OUT OF BOUNDS ERROR\n");
        return;
    }

    printf("State: ");
    // return ON / OFF state
    if (state == ON) {
        printf("Playing\n");
    } else {
        printf("Paused\n");
    }
}

/**
 * Setup function calls (initializations)
 */
inline void setup(void) {
    stdio_init_all();  // init for IO (USB in usecase)
    adc_init();        // init ADC HW for pots

    init_pause_play();  // init pause_play gpios
    init_volume();      // init volume gpios

    while (!stdio_usb_connected()) {
        sleep_ms(10);  // repeat sleep while stdio usb is not initialised
    }
}

int main() {
    setup();

    while (1) {
        printf("\n-------------------------\n");
        read_volume();      // read volume %
        read_play_state();  // read paused/playing state
        sleep_ms(500);
    }

    return 0;
}