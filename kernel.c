int pos = 0;

void print(char msg[]) // printing
{
    volatile char *screen = (volatile char *)0xB8000; 
    int i = 0;
    while (msg[i] != '\0')
    {
        *(screen + pos * 2) = msg[i];
        *(screen + pos * 2 + 1) = 0x0F;
        i = i + 1;  
        pos = pos + 1;
    }
   pos = (pos / 80 + 1) * 80;
}



void kernel_main(void)
{
    volatile char *screen = (volatile char *)0xB8000;
    for (int i = 0; i < 80 * 25; i++)
    {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = 0x0F;

    }
    print("welcome to XINL!");
    print("if you are seeing this message XINL loaded correctly with no errors.");
}
