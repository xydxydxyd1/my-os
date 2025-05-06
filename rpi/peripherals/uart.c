/******************************************************************************
* File:             uart.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface source file
*****************************************************************************/

#include "uart.h"

#include "memmap.h"

RET_Void UART_putchar(char c) {
    MM_UART0->DR = c;
    return (RET_Void){};
}
