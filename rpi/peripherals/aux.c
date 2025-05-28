#include "aux.h"


// constants

#define AUX_ENABLES ((uint32_t*)0xfe21504) // auxilliary enables
#define AUX_MU_LCR_REG ((uint32_t*)0xfe2154c) // line control
#define AUX_MU_CNTL_REG ((uint32_t*)0xfe21560) // extra control
#define AUX_MU_BAUD_REG ((uint16_t*)0xfe21568) // extra control


// methods

void aux_uart_init() {
    // Might need to unlock DLAB?
    *AUX_MU_BAUD_REG = 9600; // Set baud rate
    *AUX_MU_LCR_REG |= 1; // 8-bit mode
    *AUX_MU_CNTL_REG |= 0b10; // Enable transmitter
    *AUX_ENABLES |= 1; // Enable
}

void aux_uart_putchar(uint8_t c) {
}
