# Tutorial 1: Creating a Useless Shell

### Introduction

In this tutorial, we will create a program that boots the Pi and creates a simple shell that just displays everything the user types. There are three main portions of this program:

* The code that boots the operating system
* The mini-UART driver that can read input and write text to the terminal
* The actual kernel that is responsible for high-level logic

There is also some extra code that the Pi needs to work but we will copy from the Raspbian operating system, as well as some scripts that build the project and start the emulation.

### Booting the Pi

The Raspberry Pi has an unusual booting process. While on most devices the CPU boots first, on the Pi the GPU boots first, and then it boots the Pi. Most of the booting procedure is run on the GPU and we have very little control over it. There is a `config.txt` file that we can provide that tells the GPU about our OS, and this will be covered in the section 'Running on Hardware'. At the end of the booting procedure, the GPU will run `kernel.img`, the binary file that contains the kernel of our operating system. We will now write `boot.S`, the entry point to `kernel.img`. The first few lines of the file are shown below.

```
.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF        ;Check processor id
	cbz	x0, master		    ;Hang for all non-primary CPU
	b	proc_hang

proc_hang: 
	b 	proc_hang
```

The first two lines are notes to the linker. The first line, `.section ".text.boot"`, pertains to the location of `boot.S` in the compiled binary. The second line, `.globl _start`, tells the linker that our function `_start` should be visible from outside the assembly file.

### Building the Mini-UART Driver

### Writing the Kernel

### Building the Project

### Running on Hardware