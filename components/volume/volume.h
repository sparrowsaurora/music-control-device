/*******************************************************************
 *
 * File Name: volume.h
 *
 * Description:
 *   Public interface for volume control functionality.
 *   Provides functions to configure volume input and read
 *   volume levels in raw ADC units or percentage.
 *
 * Author: sparrow
 * Date: 16/01/26
 *
 *******************************************************************/

#ifndef VOLUME_H
#define VOLUME_H

#include <stdbool.h>
#include <stdio.h>

#include "hardware/adc.h"
#include "pico/stdlib.h"

/**
 * @brief Initialize the ADC and GPIO used for volume control.
 *
 * This function must be called before reading volume values.
 */
void configure_volume_control(void);

/**
 * @brief Read the raw ADC value of the volume control.
 *
 * @param print_voltage If true, prints the converted voltage via stdio.
 * @return Raw ADC value (12-bit, 0–4095).
 */
int read_volume_raw(bool print_voltage);

/**
 * @brief Read the volume level as a percentage.
 *
 * @return Volume percentage (implementation-defined range).
 */
int read_volume_percent(void);

#endif /* VOLUME_H */
