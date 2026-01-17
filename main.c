#include <stdio.h>

#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

// components
#include "display.h"
#include "volume.h"

void volume() {
    int volume_percentage = read_volume_percent();
    printf("Volume: %%%d\n", volume_percentage);
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    configure_volume_control();

    while (1) {
        volume();
        printf("-------------------------\n");
        sleep_ms(500);
    }

    return 0;
}