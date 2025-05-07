/******************************************************************************
* File:             uart.h
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Prefix:           UART
* Description:      UART interface, provides I/O for all UART
*****************************************************************************/

#ifndef UART_H
#define UART_H


// Includes

#include "stdint.h"


// UART Interface utils

typedef struct {
    uint32_t _DR;
} UART_Regs;

#define UART0 ((volatile UART_Regs * const)0xfe201000)
#define UART2 ((volatile UART_Regs * const)0xfe201400)
#define UART3 ((volatile UART_Regs * const)0xfe201600)
#define UART4 ((volatile UART_Regs * const)0xfe201800)
#define UART5 ((volatile UART_Regs * const)0xfe201a00)

// UART interface

/**
 * Transmit a character with UART
 *
 * Args:
 * uart - the UART device with which to transmit `c`.
 * c - the character to transmit
 */
void UART_putchar(volatile UART_Regs* const uart, char c);

/**
 * Transmit a string
 *
 * Args:
 * uart - the UART device with which to transmit `str`
 * str - the null-terminated string to transmit
 */
void UART_print(volatile UART_Regs* const uart, char* str);


#endif /* ifndef UART_H */
