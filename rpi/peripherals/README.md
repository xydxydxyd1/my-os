Contains peripheral drivers.

A driver instance is used to I/O with a device. As the basic I/O is putchar and
getchar, all device drivers starts with two function pointers.

```c
typedef struct {
    RET_Char (*putchar)();
    RET_Void (*getchar)(char);
    ...
} Device;
```
