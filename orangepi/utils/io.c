/******************************************************************************
* File:             io.c
*
* Author:           Eric Xu  
* Created:          04/30/25 
* Description:      See io.h
*****************************************************************************/

#include "io.h"


RET_Void IO_print(IO_PutChar putchar, char* fmt, ...) {
    for (int i = 0; fmt[i] != '\0'; i++) {
        putchar(fmt[i]);
    }
    return (RET_Void){};
}
