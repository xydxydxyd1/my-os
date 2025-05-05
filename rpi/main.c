/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "utils/logging.h"
 
void c_entry() {
    // Test with Hello world
    while (1)
        LOG_print("Hello, world!\r\n");

    // Halt
    while (1);
}

