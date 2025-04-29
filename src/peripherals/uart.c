/******************************************************************************
* File:             uart.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface source file
*****************************************************************************/

#include "uart.h"

#include "hardware/memmap.h"

void print_uart0(const char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        *(MM_UART0_BASE + MM_UART_DR) = s[i];
    }
}
