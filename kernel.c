void kernel_main(void)
{
    volatile char *screen = (volatile char *)0xB8000;
    *screen = ' ';
    *(screen + 1) = 0x0F;
    *(screen + 2) = 'c';
    *(screen + 3) = 0x0F;
    *(screen + 4) = ':';
    *(screen + 5) = 0x0F;
    *(screen + 6) = ' ';
    *(screen + 7) = 0x0F;
    *(screen + 8) = ' ';
    *(screen + 9) = 0x0F;
    *(screen + 10) = ' ';
    *(screen + 11) = 0x0F;
    *(screen + 12) = ' ';
    *(screen + 13) = 0x0F;

}
