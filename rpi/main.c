/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "logging.h"
#include "peripherals/uart.h"
#include "io.h"
 
void c_entry() {
    // Test with Hello world
    while (1)
        //IO_print(&UART_putchar, "Hello, world!\r\n");
        LOG_print("Hello, world!\r\n");

    // Halt
    while (1);
}

