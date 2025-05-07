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

#define GPIO ((GPIORegs*)0xfe201000)


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
