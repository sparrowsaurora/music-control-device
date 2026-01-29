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
    configure_volume_control();  // volume pot pins config
    int volume_percentage = read_volume_percent();
    printf("Volume: %%%d\n", volume_percentage);
}

void read_play_state() {
    configure_pause_play_control();
    PlayState state = read_state();
    if (state == OUT_OF_BOUNDS) {
        // error noti here
        // force continuation
        printf("STATE: OUT OF BOUNDS ERROR");
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
void setup(void) {
    stdio_init_all();  // init for IO (USB in usecase)
    adc_init();        // init ADC HW for pots

    init_pause_play();  // init pause_play gpios
    init_volume();      // init volume gpios
}

int main() {
    sleep_ms(2000);

    while (1) {
        read_volume();      // read volume %
        read_play_state();  // read paused/playing state
        printf("-------------------------\n");
        sleep_ms(500);
    }

    return 0;
}