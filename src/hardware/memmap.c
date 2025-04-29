/******************************************************************************
* File:             memmap.c
*
* Author:           Eric Xu
* Created:          04/29/25 
* Description:      Peripheral addresses source file
*****************************************************************************/

volatile unsigned int * const MM_UART0_DR = (unsigned int *)0xfe201000;
