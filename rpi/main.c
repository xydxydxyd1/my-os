/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/
#include "peripherals/gpio.h"
#include "peripherals/aux.h"
#include "types.h"

void initialize() {
    gpio_init(17, GPIO_FSEL_OUT);
    gpio_init(27, GPIO_FSEL_OUT);
    gpio_init(14, GPIO_FSEL_ALT5); // TXD1
    gpio_init(15, GPIO_FSEL_ALT5); // RXD1
    aux_uart_init();
}

void c_entry()
{
    initialize();
    gpio_set(17, FALSE);
    gpio_set(27, TRUE);
    aux_uart_printf("Hello, world!");
    gpio_set(17, TRUE);

    while(1);
}
