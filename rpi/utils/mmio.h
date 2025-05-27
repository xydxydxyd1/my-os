/******************************************************************************
* File:             mmio.h
*
* Author:           Eric Xu  
* Created:          05/27/25 
*                   Utilities for memory-mapped I/O
*****************************************************************************/
#ifndef MMIO_H
#define MMIO_H

#include <stdint.h>

/**
 * Write to `addr + offset` `nbytes` of `val`.
 *
 * Args:
 * addr - base address
 * offset - byte offset
 * nbytes - number of bytes to write
 * val - address of value to write
 */
void mmio_write(volatile uint8_t* addr, int offset, unsigned int nbytes, uint8_t *val);

/**
 * Read from `addr + offset` `nbytes` to `output`
 *
 * Args:
 * addr - base address
 * offset - byte offset
 * nbytes - number of bytes to readd
 * output - address to copy the data to
 */
void mmio_read(volatile uint8_t* addr, int offset, unsigned int nbytes, uint8_t *output);

#endif /* ifndef MMIO_H */
