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
#define GPCLR0 ((volatile unsigned long*)0xfe200028)
#define GPPUD1 ((volatile unsigned long*)0xfe2000e8)

void c_entry()
{
    *GPFSEL1 = 0b001 << 21; // 17 % 10 * 3
    *GPFSEL2 = 0b001 << 21; // 27 % 10 * 3
    *GPCLR0 |= 1 << 17 | 1 << 27;
    *GPSET0 = 1 << 17;

    /*
    *GPPUD1 = 0; // Pin 0:31 is output
    *GPFSEL1 = 0b001 << 21; // 17 % 10 * 3
    *GPFSEL2 = 0b001 << 21; // 27 % 10 * 3
    *GPCLR0 |= 1 << 17 | 1 << 27;
    *GPSET0 = 1 << 17;
    *GPCLR0 = 1 << 27;
    */

    while(1);
}

