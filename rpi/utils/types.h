/******************************************************************************
* File:             types.h
*
* Author:           Eric Xu  
* Created:          05/06/25 
* Prefix:           T
* Description:      Miscellaneous types
*****************************************************************************/

#ifndef TYPES_H
#define TYPES_H


typedef enum {
    FALSE = 0,
    TRUE = 1,
} Boolean;

typedef enum {
    SUCCESS = 0,
    ERR_OVERFLOW = -1,
} Error;


#endif /* ifndef TYPES_H */
