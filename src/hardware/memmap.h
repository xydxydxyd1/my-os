/******************************************************************************
* File:             memmap.h
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Prefix:           MM
* Description:      Peripheral addresses
*****************************************************************************/

#ifndef MEMMAP_H
#define MEMMAP_H


// UART

extern volatile unsigned int * const MM_UART0_BASE;
extern volatile unsigned int * const MM_UART2_BASE;
extern volatile unsigned int * const MM_UART3_BASE;
extern volatile unsigned int * const MM_UART4_BASE;
extern volatile unsigned int * const MM_UART5_BASE;


// UART Offsets

extern int MM_UART_DR;  // Data register


#endif /* ifndef MEMMAP_H */
