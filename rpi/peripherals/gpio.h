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


#endif /* ifndef GPIO_H */
