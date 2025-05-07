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
#define GET_MASK(offset, width) (~(~0u << width) << offset)


#endif /* ifndef BITMANIP_H */
