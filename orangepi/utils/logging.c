/******************************************************************************
* File:             logging.c
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Description:      See logging.h
*****************************************************************************/

#include "logging.h"

#include "peripherals/uart.h"   // Console
#include "utils/io.h"           // High level IO

RET_Void LOG_print(char* str) {
    return IO_print(&UART_putchar, str);
}
