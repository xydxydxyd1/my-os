# Error log

Things that I did wrong

* Wrong pin connection
    + 2025-05-16: UART vs. normal GPIO to logic
* Wrong address
    + 2025-05-16: Copied over UART register addresses instead of modifying it to GPIO addresses
    + 2025-05-17: GPCLR1 became GPCLR0
    + 2025-05-29: aux.c 215xxx became 215xx
