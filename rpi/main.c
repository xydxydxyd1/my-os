/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/

#include "logging.h"
#include "peripherals/gpio.h"
 
void c_entry() {
    LOG_init();
    GPIO_set_fsel(4, 0); // Set pin 4 to inspect clock 0

    // Test with Hello world
    while (1)
        LOG_print("Hello, world!\r\n");

    // Halt
    while (1);
}

