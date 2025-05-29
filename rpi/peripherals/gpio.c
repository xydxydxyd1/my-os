#include "gpio.h"

#include "bitmanip.h"
#include <stdint.h>


// constants

#define GPFSEL_BASE ((volatile uint32_t*)0xfe200000)
#define GPSET_REG ((volatile uint64_t*)0xfe20001c)
#define GPCLR_REG ((volatile uint64_t*)0xfe200028)
#define GPIO_PUP_PDN_CNTRL_BASE ((volatile uint32_t*)0xfe2000e4)


// Exposed interface

void gpio_init(int gpio, GpioFsel fsel) {
    volatile uint32_t *fsel_reg = GPFSEL_BASE + gpio / 10;
    int fsel_offset = (gpio % 10) * 3;
    *fsel_reg = (*fsel_reg & ~GET_MASK(fsel_offset, 3)) | fsel << fsel_offset;

    // reset pud to 0 (no resistor) instead of undefined reserved value
    volatile uint32_t *pud_reg = GPIO_PUP_PDN_CNTRL_BASE + gpio / 16;
    int pud_offset = (gpio % 16) * 2;
    *pud_reg = *pud_reg & ~GET_MASK(pud_offset, 2);
}

void gpio_set(int gpio, Boolean val) {
    if (val) *GPSET_REG |= 1 << gpio;
    else *GPCLR_REG |= 1 << gpio;
}
