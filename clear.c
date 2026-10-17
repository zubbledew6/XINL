void clear(void)
{
    volatile char *screen = (volatile char *)0xB8000;
    for (int i = 0; i < 80 * 25; i++)
    {
         
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = 0x0F;
    
    }

}