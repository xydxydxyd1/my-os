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

## Learn Assembly

Well actually, my dad told me to look into them so I will. I will start with a
Hello world C program running on QEMU: success!

Next, write ARM assembly code. According to [stack
overflow](https://stackoverflow.com/questions/12946958/what-is-the-interface-for-arm-system-calls-and-where-is-it-defined-in-the-linux)
I should consult to manpages. There are different architectures that might
apply, but I will assume Arm64 instead of EABI since I thought that was
embedded. We use `SVC`, which is inline with the programmer guide for the
architecture. Parameters are passed in registers.

My attempt failed, so I copied some random guy off the internet and succeeded.
Now I am looking into why: short answer is that I suck at Assembly. There are
some basic knowledge that I do not have.

### 2025-04-04

Where can I find the standard for the assembly language? The assembler
definitely knows so I'll look there first.

On the journey I found
[this](https://cpen432.github.io/resources/gnu_arm_ref.pdf) very helpful
reference. However, I am still curious who defines the standard.

According to GPT, while the instruction set is defined by ARM, the syntax for
the assembly language is defined by GNU. The specification can be found on
gnu.org at binutils ([](https://sourceware.org/binutils/docs/as/))

I have successfully printed a number! Now I need to learn how to link back to C.

I have run into a problem: the library functions are not being linked.

My guess is that linux/libc/lib contians the dynamic library, but I need to link
it to the static library. But if that is the case, how did I originally compile
it?

### 2025-04-05

Today's goal is to run some bootloader code with gdb. My two choices are
* CLI
* IDE

I think an IDE will have one major advantage over CLI:
> Easy to run (one button over several commands which at best can be made into a
  script)

And I want to use CLI because it generally allows me to be more in touch with
the technology I am using.

But in this case, the technology in question is the GDB debugger, and honestly I
don't really care about it. It can be a completely separate thing if I want to
study it. I am working under the assumption that IDE is easy to setup. Let's try
it for 30 minutes. It is 6 pm right now.

Ok I just don'ot realy wanna do that. I feels like copping out.

It seems like xpm is what I've been doing manually (the utils folder but better)

After literally hours of pain, I finally found an example project that actually
works, much to my joy.

https://balau82.wordpress.com/2010/02/28/hello-world-for-bare-metal-arm-using-qemu/

This journey is not fruitless however, since I did also learn about xpm, which
made my life a lot easier

### 2025-04-06

Following yesterday's work, I have successfully ran hello world on an ARM QEMU
machine. Now, I am attempting to transfer this program to raspberry pi.

The primary hurdle is the architecture: rpi4b uses AArch64, not Arm. I changed
the `-mcpu` flag and the toolchain. Additionally, I installed the newest version
of QEMU outside of XPM. This resulted in a program that doesn't output anything,
but can be linked to GDB. Additionally, I can set breakpoints in GDB but they
don't do anything.

My next step is to attempt to break at a line in GDB. This can be done for the
ARM version but can't for the new AArch64. I suspect it is because of a
different bootstrapping system.

To test this theory, I can try the old program on a different ARM machine first?

I copied `guide2` to `src`, keeping everything except the architecture the same.
* Registers turn from `r0` to `x0`
* Toolchain changed from `arm-none-eabi` to `aarch64-none-elf`
* QEMU uses different CPU
* (TODO) Different bootloading

### 2025-04-08

I am still slightly confused by the terminologies I see.
* Cortex-whatever is the CPU
    + Are peripherals like UART inside the CPU?
* Armv7-whatever is the instruction set
* AArch64 and ARM is the architecture, 64 bit and 32 bit

What is the relationship between the architecture, the core, and the instruction
set?

According to ChatGPT, the relationship goes as follows:
1. Given a CPU such as Cortex-A72
2. This CPU implements a particular instruction set architecture (ISA) such as
   Armv7
    a. Newer versions of the same architecture is backwards-compatible.
    b. An ISA may have different *profiles* (such as ARMv7-A) which targets
       different use cases
    c. The ISA defines the set of instructions available to the CPU.

Inside the book, they said that architectures are backwards compatible. If that
is the case, what is the difference between `qemu-system-arm` and
`qemu-system-aarch64`?

I found my big mistake: Cortex-A72 is **very different** from Cortex-A7. The
latter is what I have been assuming so far and reading documentation for. The
former implements ARMv8, which notably includes a 64-bit state using AArch64! I
will need to update my programmer's guide.

The booting guide says that reset vector is implementation defined. I can't find
it so I'm gonna say it is 0000.

After learning some ways to examine the machine state on QEMU, I realized that
when I run `qemu-system-arm -M raspi`, the flashed program is not present at the
right address. I want to know why. However, it is to note that the program seems
to run fine?

I found the program at 0x80000. This is not what I expected. It is related to
how QEMU load programs. The `-kernel` option is related to this. This behavior
is documented
[here](https://www.qemu.org/docs/master/system/invocation.html#hxtool-8).

The natural next step is to get Hello World working without the handholding of
`kernel`.

I have successfully loaded something into a memory location that I expect given
a particular binary file. However, the layout of the binary file is not what I
expected. The linker file `test.ld` indicates that the first memory location
should be at 0x10000, but the binary clearly shows that there is no such offset.
