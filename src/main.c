// 0x7e201000 is from the TRM. This did not work
// 0xfe201000 is from info mtree. This worked
// 0x101f1000 is from guide2
volatile unsigned int * const UART0DR = (unsigned int *)0xfe201000;
 
void print_uart0(const char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        *UART0DR = s[i];
    }
}
 
void c_entry() {
    print_uart0("Hello world!\n");
    while (1);
}

