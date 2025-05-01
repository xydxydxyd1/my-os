/******************************************************************************
* File:             uart.h
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      UART interface header file
*****************************************************************************/

#ifndef UART_H
#define UART_H


#include <stdint.h>


int UART_write(const uint8_t *s, int nbytes);


#endif /* ifndef UART_H */
