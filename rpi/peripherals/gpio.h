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
 * gpio - The GPIO to set
 * fsel - a 3-bit value that selects the functionality of the GPIO
 */
RET_Void GPIO_func_select(int gpio, char fsel);


#endif /* ifndef GPIO_H */
