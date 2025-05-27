/******************************************************************************
* File:             assert.h
*
* Author:           Eric Xu  
* Created:          05/26/25 
* Description:      Assert and other error handling related stuff
*****************************************************************************/

#ifndef ASSERT_H
#define ASSERT_H


#include "types.h"

/**
 * If `cond == FALSE`, then error with `err_msg`
 */
void assert(Boolean cond, char* err_msg);


#endif /* ifndef ASSERT_H */
