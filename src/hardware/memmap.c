/******************************************************************************
* File:             memmap.c
*
* Author:           Eric Xu
* Created:          04/29/25 
* Description:      Peripheral addresses source file
*****************************************************************************/


// UART

volatile unsigned int * const MM_UART0_BASE = (unsigned int *)0xfe201000;
volatile unsigned int * const MM_UART2_BASE = (unsigned int *)0xfe201400;
volatile unsigned int * const MM_UART3_BASE = (unsigned int *)0xfe201600;
volatile unsigned int * const MM_UART4_BASE = (unsigned int *)0xfe201800;
volatile unsigned int * const MM_UART5_BASE = (unsigned int *)0xfe201a00;
int MM_UART_DR = 0x00;
