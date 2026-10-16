ENTRY(_start)
SECTIONS
{
    . = 1M;
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    .rodata BLOCK(4k) : ALIGN(4k)
    {
        *(.rodata)
    }

    .data BLOCK(4k) : ALIGN(4k)
    {
        *(.data)
    }

    .bss BlOCK(4k) : ALIGN(4k)
    {
        *(COMMON)
        *(.bss)
    }
}
