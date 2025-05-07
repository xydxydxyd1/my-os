/******************************************************************************
* File:             uart.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface source file
*****************************************************************************/

#include "uart.h"


// Exposed interface

void UART_putchar(volatile UART_Regs* const uart, char c) {
    uart->_DR = c;
}

void UART_print(volatile UART_Regs* const uart, char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i) {
        UART_putchar(uart, str[i]);
    }
}
