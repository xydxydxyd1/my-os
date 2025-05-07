#include "gpio.h"

#include <stdint.h>


typedef struct {
    uint32_t GPFSEL[6]; // GPFSEL0 to GPFSEL5
    uint64_t GPSET;
    uint64_t GPCLR;
    uint64_t GPLEV;
} MM_GPIORegs;

volatile MM_GPIORegs * const MM_GPIO = (MM_GPIORegs*)0xfe201000;
