#include "gpio.h"

#include <stdint.h>

#include "bitmanip.h"


// GPIO interface utilities

typedef struct {
    uint32_t GPFSEL[6]; // GPFSEL0 to GPFSEL5
    uint64_t GPSET;
    uint64_t GPCLR;
    uint64_t GPLEV;
} GPIORegs;

typedef struct {
    uint32_t CMGPXCTL; // Clock manager general purpose clocks control X
    uint32_t CMGPXDIV; // Clock manager general purpose clocks divisors X
} GPIOClkRegs;


// Masks

#define CMGPX_PASSWD GET_MASK(24, 8)
#define CMGPXCTL_MASH GET_MASK(9, 2)
#define CMGPXCTL_FLIP (1u << 8) // invert generator output
#define CMGPXCTL_BUSY (1u << 7) // clock is running
#define CMGPXCTL_KILL (1u << 5) // glitchy kill
#define CMGPXCTL_ENAB (1u << 4) // glitchless enable
#define CMGPXCTL_SRC (0b1111) // clock source

#define CMGPXDIV_DIVI GET_MASK(12, 12) // integer part of divisor
#define CMGPXDIV_DIVF 0xfff // fractional part of divisor


// Preset values
#define CMGPX_PASSWD_KEY (0x5a << 8)
#define CMGPXCTL_MASH_INTDIV 0
#define CMGPXCTL_SRC_GND 0
#define CMGPXCTL_SRC_OSC 1 // oscillator

// Base addresses
#define GPIO ((GPIORegs*)0xfe201000)
#define CM_GPX ((GPIOClkRegs*)0xfe101070)   // can be indexed up to CM_GP[2]

// Misc.
#define OSC_FREQ 0x0337f980 // external oscillator frequency

// Exposed interface

void GPIO_set_fsel(int gpio, char fsel) {
    int fsel_i = gpio / 10; // Each GPFSEL register controls 10 GPIO
    int fsel_offset = gpio % 10 * 3; // The FSEL for a GPIO is 3 bits
    GPIO->GPFSEL[fsel_i] &= ~GET_MASK(fsel_offset, 3);
    GPIO->GPFSEL[fsel_i] |= fsel << fsel_offset & GET_MASK(fsel_offset, 3);
}

char GPIO_get_fsel(int gpio) {
    int fsel_i = gpio / 10;
    int fsel_offset = gpio % 10 * 3;
    return GPIO->GPFSEL[fsel_i] >> fsel_offset & 0b111;
}

void GPIO_config_clk(int gpio_bank) {
    GPIOClkRegs* clk = CM_GPX + gpio_bank;
    clk->CMGPXCTL = MASKED_UPDATE(
        clk->CMGPXCTL,
        CMGPX_PASSWD,
        CMGPX_PASSWD_KEY
    );
    clk->CMGPXDIV = MASKED_UPDATE(
        clk->CMGPXDIV,
        CMGPX_PASSWD,
        CMGPX_PASSWD_KEY
    );
    clk->CMGPXCTL &= ~CMGPXCTL_ENAB;

    clk->CMGPXCTL = MASKED_UPDATE(clk->CMGPXCTL, CMGPXCTL_SRC, CMGPXCTL_SRC_OSC);
    clk->CMGPXDIV = MASKED_UPDATE(
        clk->CMGPXDIV,
        CMGPXDIV_DIVI,
        OSC_FREQ / GPIO_FREQ
    );

    clk->CMGPXCTL |= CMGPXCTL_ENAB;
    clk->CMGPXCTL = MASKED_UPDATE(clk->CMGPXCTL, CMGPX_PASSWD, 0);
    clk->CMGPXDIV = MASKED_UPDATE(clk->CMGPXDIV, CMGPX_PASSWD, 0);
}
