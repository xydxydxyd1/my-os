## Todo

* GPIO control


## What isn't done by me

* Linker script (rpi4-osdev)


## RPIOS

This project is meant to teach me about operating systems and bare-metal
programming.

The project will have three folders:
* `./src/` contains the source code for the project
* `./references/` (Not pushed) contains the documentations frequently used.
* `./guide<id>` contains the code sampled from a particular guide. See [guides
used](#guides-used)

## Guides used

Guides are walkthroughs of solution of a particular problem. I try not to use
them because I learn the most by struggling through a problem myself. I use them
if I have been stuck on a problem for a significant amount of time without
making progress.

* [Baremetal
   qemu](https://balau82.wordpress.com/2010/02/28/hello-world-for-bare-metal-arm-using-qemu/)
   from [balau](https://balau82.wordpress.com/)
    + Minimalist bootstrapping reference
* [RPI4OS](https://www.rpi4os.com/)
    + Control environment for booting code
* [RPI3OS](https://github.com/bztsrc/raspi3-tutorial/)


## Flashing

1. Prepare a normal Raspbian installation medium on an SD card (only need to do
   once)
2. Replace kernel
    a. Remove all `kernel*` files on the SD card
    b. Copy in the built `kernel8.img`
