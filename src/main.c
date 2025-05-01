/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "peripherals/uart.h"
#include "utils/io.h"
 
void c_entry() {
    IO_print(&UART_putchar, "Hello world!\n");
    while (1);
}

