#include "aux.h"
#include <stdarg.h>


// constants

#define AUX_ENABLES ((volatile uint32_t*)0xfe21504) // auxilliary enables
#define AUX_MU_IO_REG ((volatile uint32_t*)0xfe21540) // input/output
#define AUX_MU_LCR_REG ((volatile uint32_t*)0xfe2154c) // line control
#define AUX_MU_LSR_REG ((volatile uint32_t*)0xfe21554) // line status
#define AUX_MU_CNTL_REG ((volatile uint32_t*)0xfe21560) // extra control
#define AUX_MU_BAUD_REG ((volatile uint16_t*)0xfe21568) // baudrate control


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

Error aux_uart_putchar(uint8_t c) {
    if ((*AUX_MU_LSR_REG & 1 << 5) == 0)
        return ERR_OVERFLOW;
    *AUX_MU_IO_REG = (*AUX_MU_IO_REG & ~0xff) | c;
    return SUCCESS;
}

void aux_printf(char* fmtstr, ...) {
    for (int i = 0; fmtstr[i] != '\0'; i++) {
        while (aux_uart_putchar(fmtstr[i]) == ERR_OVERFLOW);
    }
}
