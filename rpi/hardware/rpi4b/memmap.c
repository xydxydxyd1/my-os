/******************************************************************************
* File:             memmap.c
*
* Author:           Eric Xu
* Created:          04/29/25 
* Description:      Peripheral addresses source file
*****************************************************************************/


#include "memmap.h"


// UART

volatile MM_UART * const MM_UART0 = (MM_UART *)0xfe201000;
volatile MM_UART * const MM_UART2 = (MM_UART *)0xfe201400;
volatile MM_UART * const MM_UART3 = (MM_UART *)0xfe201600;
volatile MM_UART * const MM_UART4 = (MM_UART *)0xfe201800;
volatile MM_UART * const MM_UART5 = (MM_UART *)0xfe201a00;
