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


#include <stdint.h>


// UART

typedef struct {
    uint32_t DR;
} MM_UART;

extern volatile MM_UART * const MM_UART0;
extern volatile MM_UART * const MM_UART2;
extern volatile MM_UART * const MM_UART3;
extern volatile MM_UART * const MM_UART4;
extern volatile MM_UART * const MM_UART5;


#endif /* ifndef MEMMAP_H */
