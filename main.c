#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

//components
#include "volume.h"


int main() {
    stdio_init_all();
    sleep_ms(2000);
    
    configure_volume_control();

    while (1) {
        int volume_percentage = read_volume_percent();
        printf("Volume: %%%d\n", volume_percentage);
        printf("-------------------------\n");
        sleep_ms(500);
    }

    return 0;
}