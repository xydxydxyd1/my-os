.data

/* Data segment: define our message string and calculate its length. */
msg:
    .ascii        "Hello, ARM64!\n"
len = . - msg

msg2:
    .space 64

.text

/* Our application's entry point. */
.globl _start
_start:
    /* syscall write(int fd, const void *buf, size_t count) */
    mov     x0, #1      /* fd := STDOUT_FILENO */
    ldr     x1, =msg    /* buf := msg */
    ldr     x2, =len    /* count := len */
    mov     w8, #64     /* write is syscall #64 */
    svc     #0          /* invoke syscall */

    /* Given a number, get a decimal ascii message */
    mov     x0, #52     /* number to be saved */
    mov     x2, #10
    ldr     x3, =msg2
    mov     x4, #0
    mov     x1, x0      /* calculate remainder */
    sdiv    x1, x1, x2
    msub    x1, x1, x2, x0
    add     x1, x1, '0  /* calculate ascii */
    str     x1, [x3, x4]/* store to msg2 */

    /* syscall write(int fd, const void *buf, size_t count) */
    mov     x0, #1      /* fd := STDOUT_FILENO */
    ldr     x1, =msg2   /* buf := msg */
    mov     x2, #2      /* count := len */
    mov     w8, #64     /* write is syscall #64 */
    svc     #0          /* invoke syscall */

    /* syscall exit(int status) */
    mov     x0, #0      /* status := 0 */
    mov     w8, #93     /* exit is syscall #93 */
    svc     #0          /* invoke syscall */

