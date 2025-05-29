/******************************************************************************
* File:             aux.h
*
* Author:           Eric Xu  
* Created:          05/27/25 
* Prefix:           aux
* Description:      Auxilliary systems to assist with (debugging) low-level 
*                   stuff.
*****************************************************************************/

#ifndef AUX_H
#define AUX_H 


// includes
#include <stdint.h>
#include "types.h"


// methods

/**
 * Initializes auxilliary UART with a baud rate of 115200.
 *
 * Assumes that config.txt set the core_freq_min=500, otherwise baud rate may
 * vary.
 */
void aux_uart_init();

/**
 * Attempts to transmits a single character through the auxilliary UART.
 * Non-blocking.
 *
 * Assumes that `aux_uart_init()` is called before.
 *
 * Returns: `ERR_OVERFLOW` if transmit FIFO is full, `SUCCESS` otherwise.
 */
Error aux_uart_putchar(uint8_t c);

/**
 * printf onto the auxilliary uart.
 *
 * Assumes that `aux_uart_init()` is called before
 *
 * Currently, flags are not implemented.
 */
void aux_uart_printf(char* fmtstr, ...);


#endif /* ifndef AUX_H */
