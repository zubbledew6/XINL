bits 32

section .multiboot
dd 0x1BADB002
dd 0x0
dd -(0x1BADB002 + 0x0)

section .bss
align 16
stack_bottom:
resb 16384
stack_top:

section .text
extern kernel_main
global _start
_start:
mov esp, stack_top
call kernel_main
.crib:
cli
hlt
jmp .crib
