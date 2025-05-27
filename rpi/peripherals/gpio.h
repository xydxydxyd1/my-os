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


typedef enum {
    GPIO_FSEL_IN = 0b000,
    GPIO_FSEL_OUT = 0b001,
    GPIO_FSEL_ALT0 = 0b100,
    GPIO_FSEL_ALT1 = 0b101,
    GPIO_FSEL_ALT2 = 0b110,
    GPIO_FSEL_ALT3 = 0b111,
    GPIO_FSEL_ALT4 = 0b011,
    GPIO_FSEL_ALT5 = 0b010,
} GPIO_FSEL;

/**
 * Initialize a GPIO pin with a function select
 *
 * Args:
 * gpio - 0:57 GPIO pin number
 * fsel - function select value
 */
void gpio_init(int gpio, GPIO_FSEL fsel);


#endif /* ifndef GPIO_H */
