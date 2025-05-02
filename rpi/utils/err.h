/******************************************************************************
* File:             err.h
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Prefix:           ERR, RET (because RET_whatever makes a lot of sense)
* Description:      Error model
*****************************************************************************/

#ifndef ERR_H
#define ERR_H


// Possible error codes
typedef enum {
    ERR_NONE = 0,   // no errors raised
} ERR_Code;


// Return types. They attach an err value to an return.

typedef struct {
    ERR_Code err;
} RET_Void;


#endif /* ifndef ERR_H */
