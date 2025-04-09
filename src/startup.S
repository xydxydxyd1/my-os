.global _Reset
_Reset:
    mov     x0, #5
_loop_start:
    add     x0, x0, #1
    b       _loop_start
