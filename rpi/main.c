/******************************************************************************
* File:             main.c
*
* Author:           Eric Xu  
* Created:          04/29/25 
* Description:      Main routine.
*****************************************************************************/
#define GPFSEL1 ((volatile unsigned long*)0xfe200004)
#define GPFSEL2 ((volatile unsigned long*)0xfe200008)
#define GPSET0 ((volatile unsigned long*)0xfe20001c)
#define GPCLR0 ((volatile unsigned long*)0xfe20002c)
#define GPPUD1 ((volatile unsigned long*)0xfe2000e8)

void c_entry()
{
    *GPPUD1 = 0; // Pin 0:31 is output
    *GPFSEL1 = 0b001 << 21; // 17 % 10 * 3
    *GPFSEL2 = 0b001 << 21; // 27 % 10 * 3
    *GPSET0 = 1 << 17;
    *GPCLR0 = 1 << 27;

    while(1);
}


//#include "peripherals/gpio.h"
//
//
///**
// * Simple program that sets a GPIO pin high and another low
// */
//void set_gpio() {
//    GPIO_set_fsel(17, GPIO_FSEL_OUT);
//    GPIO_set_fsel(27, GPIO_FSEL_OUT);
//    GPIO_set(17);
//    GPIO_clr(27);
//}
//
//void c_entry() {
//    set_gpio();
//
//    // Catch-all halt
//    while (1);
//}
//
