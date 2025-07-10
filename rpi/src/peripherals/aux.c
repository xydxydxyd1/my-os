#include "aux.h"
#include <stdarg.h>

// constants

#define AUX_ENABLES ((volatile uint32_t*)0xfe215004) // auxilliary enables
#define AUX_MU_IO_REG ((volatile uint32_t*)0xfe215040) // input/output
#define AUX_MU_IER_REG ((volatile uint32_t*)0xfe215044)
#define AUX_MU_IIR_REG ((volatile uint32_t*)0xfe215048)
#define AUX_MU_LCR_REG ((volatile uint32_t*)0xfe21504c) // line control
#define AUX_MU_MCR_REG ((volatile uint32_t*)0xfe215050) // line control
#define AUX_MU_LSR_REG ((volatile uint32_t*)0xfe215054) // line status
#define AUX_MU_MSR_REG ((volatile uint32_t*)0xfe215058)
#define AUX_MU_SCRATCH ((volatile uint32_t*)0xfe21505c)
#define AUX_MU_CNTL_REG ((volatile uint32_t*)0xfe215060) // extra control
#define AUX_MU_STAT_REG ((volatile uint32_t*)0xfe215064)
#define AUX_MU_BAUD_REG ((volatile uint16_t*)0xfe215068) // baudrate control


// methods

void aux_uart_init() {
    *AUX_ENABLES = 1; // Enable

    // Might need to unlock DLAB?
    // Set baud rate
    const int CLK_FREQ = 500000000;
    const int BAUD_RATE = 115200;
    *AUX_MU_BAUD_REG = CLK_FREQ / (BAUD_RATE * 8) - 1;

    // As of 2025-05-29, documentation is wrong on LCR_REG.
    // https://github.com/raspberrypi/documentation/issues/2717
    *AUX_MU_LCR_REG = 3; // 8-bit mode
    *AUX_MU_CNTL_REG = 2; // Enable transmitter
}

Error aux_uart_putchar(uint8_t c) {
    if ((*AUX_MU_LSR_REG & 0x20) == 0)
        return ERR_OVERFLOW;
    *AUX_MU_IO_REG = c;
    return SUCCESS;
}

void aux_uart_printf(char* fmtstr, ...) {
    for (int i = 0; fmtstr[i] != '\0'; i++) {
        while (aux_uart_putchar(fmtstr[i]) == ERR_OVERFLOW);
    }
}
