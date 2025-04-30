/******************************************************************************
* File:             uart.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface source file
*****************************************************************************/

#include "uart.h"

#include "hardware/memmap.h"

int write(const uint8_t *s, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        MM_UART0->DR = s[i];
    }
    return i;
}
Write UART_write = &write;
