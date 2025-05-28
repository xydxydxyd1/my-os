/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/
#include "peripherals/gpio.h"
#include "types.h"

void c_entry()
{
    gpio_init(17, GPIO_FSEL_OUT);
    gpio_init(27, GPIO_FSEL_OUT);
    gpio_set(17, FALSE);
    gpio_set(27, TRUE);

    //gpio_init(4, GPIO_FSEL_ALT0); // GPCLK0

    while(1);
}
