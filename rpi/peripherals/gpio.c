#include "gpio.h"

#include <stdint.h>


// GPIO interface utilities

#define GPFSEL0 ((volatile uint32_t*)0xfe200000)
#define GPFSEL1 ((volatile uint32_t*)0xfe200004)
#define GPFSEL2 ((volatile uint32_t*)0xfe200008)
#define GPFSEL3 ((volatile uint32_t*)0xfe20000c)
#define GPFSEL4 ((volatile uint32_t*)0xfe200010)
#define GPFSEL5 ((volatile uint32_t*)0xfe200014)

#define GPSET0 ((volatile uint32_t*)0xfe20001c)
#define GPCLR0 ((volatile uint32_t*)0xfe200028)
#define GPPUD1 ((volatile uint32_t*)0xfe2000e8)

volatile uint32_t *FSEL_REGS[6] = {
    GPFSEL0,
    GPFSEL1,
    GPFSEL2,
    GPFSEL3,
    GPFSEL4,
    GPFSEL5,
};


// Exposed interface

void gpio_init(int gpio, GPIO_FSEL fsel) {
    volatile uint32_t fsel_reg = FSEL_REGS[gpio / 10];
    int fsel_offset = (gpio % 10) * 3;
}
