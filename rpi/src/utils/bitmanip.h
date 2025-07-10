/******************************************************************************
* File:             bitmanip.h
*
* Author:           Eric Xu  
* Created:          05/06/25 
* Prefix:           BIT
* Description:      Utilities that help with bit manipulation
*****************************************************************************/

#ifndef BITMANIP_H
#define BITMANIP_H


#include <stdint.h>


// Use macro for type flexibility and speed for a common and small operation

/**
 * Expands to a bitmask with specific offset and width
 *
 * Assume that width and offset are within bounds.
 *
 * Args:
 * offset - the positive integer position of the first 1 in the mask
 * width - the positive integer number of 1's in the mask
 */
#define GET_MASK(offset, width) (~(~0u << width) << offset)

/**
 * Expands to `base` with the bits masked by `mask` changed to the
 * corresponding bits on `val`
 */
#define MASKED_UPDATE(base, mask, val) ((~mask | base) | (mask & val))


#endif /* ifndef BITMANIP_H */
