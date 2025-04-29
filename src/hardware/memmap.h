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


// 0x7e201000 is from the TRM. This did not work
// 0xfe201000 is from info mtree. This worked
// 0x101f1000 is from guide2
volatile unsigned int * const MM_UART0_DR = (unsigned int *)0xfe201000;


#endif /* ifndef MEMMAP_H */
