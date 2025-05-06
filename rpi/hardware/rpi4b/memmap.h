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


// GPIO

typedef struct {
    uint32_t GPFSEL[6]; // GPFSEL0 to GPFSEL5
    uint64_t GPSET;
    uint64_t GPCLR;
    uint64_t GPLEV;
} MM_GPIORegs;

extern volatile MM_GPIORegs * const MM_GPIO;


// UART

typedef struct {
    uint32_t DR;
} MM_UARTRegs;

extern volatile MM_UARTRegs * const MM_UART0;
extern volatile MM_UARTRegs * const MM_UART2;
extern volatile MM_UARTRegs * const MM_UART3;
extern volatile MM_UARTRegs * const MM_UART4;
extern volatile MM_UARTRegs * const MM_UART5;


#endif /* ifndef MEMMAP_H */
