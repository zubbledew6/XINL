bits 32 ;32 for now

section .multiboot
dd 0x1BADB002 ; kernel ID
dd 0x0
dd -(0x1BADB002 + 0x0)

section .bss ; reserved memory
align 16
stack_bottom:
resb 16384
stack_top:

section .text ; CPU intructions
extern kernel_main
global _start
_start:
mov esp, stack_top
call kernel_main ; communication with kernel_main
.crib:
cli
hlt
jmp .crib
