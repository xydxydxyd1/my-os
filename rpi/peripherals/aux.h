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


// methods

/**
 * Initializes auxilliary UART with a baud rate of 9600.
 *
 * Assumes that config.txt set the core_freq_min=500, otherwise baud rate may
 * vary.
 */
void aux_uart_init();

/**
 * Transmits a single character through the auxilliary UART.
 *
 * Assumes that `aux_uart_init()` is called before.
 */
void aux_uart_putchar(uint8_t c);


#endif /* ifndef AUX_H */
