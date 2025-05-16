/******************************************************************************
* File:             logging.c
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Description:      See logging.h
*****************************************************************************/

#include "logging.h"

#include "peripherals/gpio.h"
#include "peripherals/uart.h"


#define CONSOLE UART0


void LOG_init() {
    GPIO_set_fsel(14, GPIO_FSEL_ALT0);   // GPIO[14].FSEL = TXD0
    GPIO_set_fsel(15, GPIO_FSEL_ALT0);   // GPIO[15].FSEL = RXD0
    // I don't know which clock it is so I will set all of them
    GPIO_config_clk(0);
    GPIO_config_clk(1);
    GPIO_config_clk(2);
    UART_init(CONSOLE);
}

void LOG_print(char* str) {
    UART_print(CONSOLE, str);
}
