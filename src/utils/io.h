/******************************************************************************
* File:             io.h
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Prefix:           IO
* Description:      Provide higher-level I/O above device interface
*****************************************************************************/

#ifndef IO_H
#define IO_H


#include "utils/err.h"

/**
 * A PutChar function writes a single character
 */
typedef RET_Void (*IO_PutChar)(char c);

/**
 * Given a format string, print via putchar.
 *
 * A format string is a null-terminated string with flags like printf.
 *
 * Currently supported flags: None
 */
RET_Void IO_print(IO_PutChar putchar, char* fmt, ...);


#endif /* ifndef IO_H */
