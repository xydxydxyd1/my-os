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

volatile UART_Regs * const CONSOLE = UART0;


void LOG_init() {
    GPIO_set_fsel(14, 0);   // GPIO[14].FSEL = TXD0
    GPIO_set_fsel(15, 0);   // GPIO[15].FSEL = RXD0
}

void LOG_print(char* str) {
    UART_print(CONSOLE, str);
}
