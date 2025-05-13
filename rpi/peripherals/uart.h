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
    uint32_t _DR; // Data
    uint32_t _RSRECR; // Receive status/Error clear
    uint8_t _UNUSED0[24];
    uint32_t _FR; // Flag
    uint8_t _UNUSED1[4];
    uint32_t _IBRD; // Integer baud rate divisor
    uint32_t _FBRD; // Fractional baud rate divisor
    uint32_t _LCRH; // Line control
    uint32_t _CR; // Control
} UART_Regs;

#define UART0 ((volatile UART_Regs * const)0xfe201000)
#define UART2 ((volatile UART_Regs * const)0xfe201400)
#define UART3 ((volatile UART_Regs * const)0xfe201600)
#define UART4 ((volatile UART_Regs * const)0xfe201800)
#define UART5 ((volatile UART_Regs * const)0xfe201a00)

#define UART_BAUDRATE 9600


// UART interface

/**
 * Initialize a UART device with default configuration
 */
void UART_init(volatile UART_Regs* uart);

/**
 * Transmit a character with UART
 *
 * Args:
 * uart - the UART device with which to transmit `c`.
 * c - the character to transmit
 */
void UART_putchar(volatile UART_Regs* uart, char c);

/**
 * Transmit a string
 *
 * Args:
 * uart - the UART device with which to transmit `str`
 * str - the null-terminated string to transmit
 */
void UART_print(volatile UART_Regs* uart, char* str);


#endif /* ifndef UART_H */
