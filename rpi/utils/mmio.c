#include "mmio.h"

void mmio_write(volatile uint8_t *addr, int offset, unsigned int nbytes, uint8_t *val) {
    addr += offset;
    for (; nbytes != 0; nbytes--) {
        *addr = *val;
        addr++;
        val++;
    }
}
void mmio_read(volatile uint8_t *addr, int offset, unsigned int nbytes, uint8_t *output) {
    addr += offset;
    for (; nbytes != 0; nbytes--) {
        *output = *addr;
        addr++;
        output++;
    }
}
