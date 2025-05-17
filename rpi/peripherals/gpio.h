/******************************************************************************
* File:             gpio.h
*
* Author:           Eric Xu  
* Created:          05/06/25 
* Prefix:           GPIO
* Description:      GPIO driver for a single pin
*****************************************************************************/

#ifndef GPIO_H
#define GPIO_H


#include <stdint.h>
#include "err.h"


#define GPIO_FREQ 0x0337f980 // clock frequency of configured clocks

/**
 * Values for the FSEL register
 */
typedef enum {
    GPIO_FSEL_IN,
    GPIO_FSEL_OUT,
    GPIO_FSEL_ALT0,
    GPIO_FSEL_ALT1,
    GPIO_FSEL_ALT2,
    GPIO_FSEL_ALT3,
    GPIO_FSEL_ALT4,
    GPIO_FSEL_ALT5,
} GPIO_FSEL;

/**
 * Set function select for a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin number whose function select is to be set
 * fsel - a 3-bit function select of the GPIO
 */
void GPIO_set_fsel(int gpio, GPIO_FSEL fsel);

/**
 * Get function select for a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin number whose function select is to be set
 *
 * Returns:
 * 3 bit fsel value corresonding to GPIO
 */
GPIO_FSEL GPIO_get_fsel(int gpio);

/**
 * Set a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin number whose function select is to be set
 */
void GPIO_set(int gpio);

/**
 * CLear a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin number whose function select is to be set
 */
void GPIO_clr(int gpio);

/**
 * Configure a Clock Manager corresponding to the GPIO bank
 *
 * Args:
 * gpio_bank - The GPIO bank (0:2)
 */
void GPIO_config_clk(int gpio_bank);


#endif /* ifndef GPIO_H */
