## Structure

* `peripherals` - peripheral drivers
* `utils` - utility stuff used everywhere

## `peripherals`

### `peripherals/aux.h`

This interface controls the auxilliary systems (so far only UART1). This is used
for debugging as it is easy to setup at the beginning.

### `peripherals/gpio.h`

GPIO functionality. Currently supports simple input/output.


## `utils`

Utility stuff used everywhere


### `utils/types.h`

Contain types like `Boolean`


### `utils/bitmanip.h`

For bit manipulation (commonly used for MMIO). `GET_MASK` is the primary thing.
