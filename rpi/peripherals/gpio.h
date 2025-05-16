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


#include "err.h"


#define GPIO_FREQ 0x0337f980 // clock frequency of configured clocks

/**
 * Set function select for a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin whose function select is to be set
 * fsel - a 3-bit function select of the GPIO
 */
void GPIO_set_fsel(int gpio, char fsel);

/**
 * Get function select for a GPIO pin
 *
 * Args:
 * gpio - The GPIO pin whose function select is to be set
 *
 * Returns:
 * 3 bit fsel value corresonding to GPIO
 */
char GPIO_get_fsel(int gpio);

/**
 * Configure a Clock Manager corresponding to the GPIO bank
 *
 * Args:
 * gpio_bank - The GPIO bank (0:2)
 */
void GPIO_config_clk(int gpio_bank);


#endif /* ifndef GPIO_H */
