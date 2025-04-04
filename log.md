### 2025-04-03

Now, let's first bootstrap. I have a **Raspberry Pi 4 Model B**. This RPI
includes a **ARM Cortex-A72** CPU, which implements the **ARMv8-A**
architecture. In this architecture, one of the more predominant instruction set
is **A64**, which I presume to be important. The **Programmer's Guide** for this
architecture can be found in `./references/cortex_a-programming.pdf`.

Section 13 discusses boot code. But before that, it is wise to run any AArch64
code at all. This requires knowledge from Appendix B.3.

The problem is that I can't ease into it or debug it. Bootloader either works or
doesn't work. I have no way of seeing what is happening. I need to first get
qemu working to run raspbian.

After a brief look, I don't think it is worth it to pursue this. My alternative
is to use JTAG to inspect the physical device' operation.

I am faced with a conundrum.

The bootloader is giving me a huge amount of trouble. This is stopping all of my
progress and I am like a headless chicken. I need knowledge in all of the
following nontrivial things:
* A64 assembly
* Cortex-A72 booting
* Compilation and linking
    + linker script

I've decided to ignore these topics for now and copy code from
[](https://www.rpi4os.com/part1-bootstrapping/). I should clearly mention it.

Ok wait, my dad just said you should learn it so I guess I am learning it.

### 2025-04-02

I want to flash a program onto the board without using the provided IDE to learn
about this process.

This requires documentation for the board (c3200 launchxl).

The problem is that doing things carelessly can adversely impact my ability to
do my assignment, so I think I'll do it on raspberry pi instead.

To reiterate, I need to flash a program onto raspberry.
* pi-gen: too high level
* yocto: nah, let's use
* buildroot: noo, both yocto and buildroot are for customizing existing
operating systems, not building your own.

I think I am confused at what level I am working at. Here is the criteria:
* No operating system
    + No file system

But without an operating system, how is memory accessed?

And then I came upon this site:
[](https://www.rpi4os.com/)

This is great. Now I am learning about EABI and ELF. It seems that EABI
specifies the binary format, and ELF adds addditional metadata on top of it to
support additional features. As such, for my functionality, I can likely use
eabi for now (moving to elf should always be possible later).

To make development easier, I will also look into QEMU for emulating the RPI.

