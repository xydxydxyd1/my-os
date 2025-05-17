/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "peripherals/gpio.h"


/**
 * Simple program that sets a GPIO pin high and another low
 */
void set_gpio() {
    GPIO_set_fsel(17, GPIO_FSEL_OUT);
    GPIO_set_fsel(27, GPIO_FSEL_OUT);
    GPIO_set(17);
    GPIO_clr(27);
}

void c_entry() {
    set_gpio();

    // Catch-all halt
    while (1);
}

