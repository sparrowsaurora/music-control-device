#include <stdio.h>

#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

// components
#include "display.h"
#include "volume.h"

/**
 * get & display volume compnent reading
 */
void read_volume() {
    int volume_percentage = read_volume_percent();
    printf("Volume: %%%d\n", volume_percentage);
}

int main() {
    stdio_init_all();  // init for IO (USB in usecase)
    sleep_ms(2000);

    configure_volume_control();  // volume pot pins config

    while (1) {
        read_volume();  // read volume %
        printf("-------------------------\n");
        sleep_ms(500);
    }

    return 0;
}