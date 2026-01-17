#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#include "components/volume/volume.h"

int main() {
    stdio_init_all();
    sleep_ms(2000);
    printf("ADC Example, measuring GPIO26\n");

    adc_init();

    adc_gpio_init(26); // GPIO26 corresponds to ADC0
    adc_select_input(0); // Select ADC0
    sleep_ms(100); // Wait for ADC to stabilize
    
    while (1) {
        // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();
        printf("Raw value: 0x%03x, val voltage: %f V\n", result, result * conversion_factor);
        // value as a percentage
        float percentage = ((result * 100.0f) / 2047.5f) - 100.0f; // old 4095
        printf("Percentage: %f %%\n", percentage);
        // printf("Volume Level: %d\n", get_volume_level());
        printf("-------------------------\n");
        sleep_ms(500);
    }

    return 0;
}