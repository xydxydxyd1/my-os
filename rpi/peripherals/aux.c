#include "aux.h"


// constants

#define AUX_ENABLES ((uint32_t*)0xfe21504) // auxilliary enables
#define AUX_MU_LCR_REG ((uint32_t*)0xfe2154c) // line control
#define AUX_MU_CNTL_REG ((uint32_t*)0xfe21560) // extra control
#define AUX_MU_BAUD_REG ((uint16_t*)0xfe21568) // extra control


// methods

void aux_uart_init() {
    // Might need to unlock DLAB?
    // Set baud rate
    const int CLK_FREQ = 500000000;
    const int BAUD_RATE = 9600;
    *AUX_MU_BAUD_REG = CLK_FREQ / BAUD_RATE / 8 - 1;

    *AUX_MU_LCR_REG |= 1; // 8-bit mode
    *AUX_MU_CNTL_REG |= 0b10; // Enable transmitter
    *AUX_ENABLES |= 1; // Enable
}

void aux_uart_putchar(uint8_t c) {
}
