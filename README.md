# XINL — XINL Is Not Linux

A fully independent kernel, written from scratch.

Made for fun, with no intention of being user-friendly.

XINL is an independent kernel with no code derived from Linux or Unix kernels. Its goal is to be its own thing, rather than another attempt at recreating an existing operating system.


## What is XINL?

XINL is an experimental kernel project built from the ground up. It exists because I wanted to make a kernel, not because the world desperately needed another one.

There is no guarantee that it will work, no guarantee that it will ever be finished, and absolutely no guarantee that it will be useful.

## how can i install XINL?
* install qemu
* install gcc
* download and extract XINL
* cd into it and ```gcc -m32 -ffreestanding -fno-pie -c kernel.c -o kernel.o && ld -m elf_i386 -T linker.ld -nostdlib -o kernel.bin boot.o kernel.o```
* then simply run ```qemu-system-i386 -kernel kernel.bin```
