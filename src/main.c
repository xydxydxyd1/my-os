/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "peripherals/uart.h"
 
void c_entry() {
    UART_write("Hello world!\n", 13);
    while (1);
}

