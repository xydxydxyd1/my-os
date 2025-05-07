/******************************************************************************
* File:             logging.c
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Description:      See logging.h
*****************************************************************************/

#include "logging.h"

#include "peripherals/uart.h"

volatile UART_Regs * const CONSOLE = UART0;

void LOG_print(char* str) {
    UART_print(CONSOLE, str);
}
