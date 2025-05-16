/******************************************************************************
* File:             uart.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface source file
*****************************************************************************/

#include "uart.h"

#include "gpio.h"


// Utils

// Masks
#define CR_RXE (1u << 9)
#define CR_TXE (1u << 8)
#define CR_UARTEN (1u)
#define FR_BUSY (1u << 3)
#define IBRD_IBRD GET_MASK(0, 16)
#define FBRD_FBRD GET_MASK(0, 6)
#define LCRH_FEN (1u << 4)


// Exposed interface

void UART_init(volatile UART_Regs* uart) {
                                    // CR program insturctions
    uart->_CR &= ~CR_UARTEN;        // 1. Disable UART
    while (uart->_FR & FR_BUSY);    // 2. Wait for end of transmission
    uart->_LCRH &= ~LCRH_FEN;       // 3. Flush transmit FIFO

    // 4. Reprogram
    uart->_CR = 0;
    // Enable transmission and reception
    uart->_CR |= CR_RXE;
    uart->_CR |= CR_TXE;
    // Baud rate
    uart->_IBRD = GPIO_FREQ / (16 * UART_BAUDRATE);
    uart->_FBRD = (GPIO_FREQ % (16 * UART_BAUDRATE)) * 64;

    // 5. Enable UART
    uart->_CR |= CR_UARTEN;
}

void UART_putchar(volatile UART_Regs* uart, char c) {
    uart->_DR |= c;
}

void UART_print(volatile UART_Regs* uart, char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i) {
        UART_putchar(uart, str[i]);
    }
}
