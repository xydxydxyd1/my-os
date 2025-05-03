# Style guide


## Naming

Due to lack of namespaces in C, all identifiers are prepended with a unique
code representing the source/header file they belong to. Other than that, use
snake_case for function and variable names, ALL_CAPS for constants, PascalCase
for types and structs.

An exception to the prefix rule is the utils; the goal of utils is to make the
program more writable so long prefixes defeats the point. Additionally, due to
their ubiquitousness, I believe it is safe to assume that utils declarations
would not be repeated.


## Spacing

Each top-level block should be separated by two lines of whitespace. If a
comment refers to a block, there should be two lines before it and one line
between it and the start of the block it is commenting. This is so that comments
for an element inside the block is clearly delineated.

A block is a group of related expressions. A function is always a block of
itself. Do not use additional whitespace for higher level blocks because that
seems like too much whitespace.

```c
// Global variables

// PL011 UART address
const volatile unsigned int * UART0_BASE = 0xfe20000;
// MiniUART address
const volatile unsigned int * UART1_BASE = 0xfe40000;


// Function definitions

// Say hi
void hi() {
    *UART0_BASE = "Hello, world!";
}
```
