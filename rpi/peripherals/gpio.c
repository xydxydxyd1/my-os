#include "gpio.h"

#include "assert.h"
#include "bitmanip.h"
#include <stdint.h>


// constants

#define GPFSEL0 ((volatile uint32_t*)0xfe200000)
#define GPFSEL1 ((volatile uint32_t*)0xfe200004)
#define GPFSEL2 ((volatile uint32_t*)0xfe200008)
#define GPFSEL3 ((volatile uint32_t*)0xfe20000c)
#define GPFSEL4 ((volatile uint32_t*)0xfe200010)
#define GPFSEL5 ((volatile uint32_t*)0xfe200014)

#define GPSET ((volatile uint64_t*)0xfe20001c)
#define GPCLR ((volatile uint64_t*)0xfe200028)
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

void gpio_init(int gpio, GpioFsel fsel) {
    volatile uint32_t *fsel_reg = FSEL_REGS[gpio / 10];
    int fsel_offset = (gpio % 10) * 3;
    *fsel_reg = (*fsel_reg & ~GET_MASK(fsel_offset, 3)) | 0b111 << fsel_offset;
}

void gpio_set(int gpio, Boolean val) {
    if (val) *GPSET |= 1 << gpio;
    else *GPCLR |= 1 << gpio;
}
