/******************************************************************************
* File:             memmap.c
*
* Author:           Eric Xu
* Created:          04/29/25 
* Description:      Peripheral addresses source file
*****************************************************************************/


#include "memmap.h"


// GPIO

volatile MM_GPIORegs * const MM_GPIO = (MM_GPIORegs*)0xfe201000;


// UART

volatile MM_UARTRegs * const MM_UART0 = (MM_UARTRegs *)0xfe201000;
volatile MM_UARTRegs * const MM_UART2 = (MM_UARTRegs *)0xfe201400;
volatile MM_UARTRegs * const MM_UART3 = (MM_UARTRegs *)0xfe201600;
volatile MM_UARTRegs * const MM_UART4 = (MM_UARTRegs *)0xfe201800;
volatile MM_UARTRegs * const MM_UART5 = (MM_UARTRegs *)0xfe201a00;
