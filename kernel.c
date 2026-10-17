int pos = 0;
extern char keys[128];
extern char shift_keys[128];
void set_keys(void);
void clear(void);

char inb(short port) // input byte from hardware
{
    char binary;

    __asm__ volatile ("inb %1, %0":"=a"(binary) : "Nd"(port));
    return binary;
}

void outb(short port, char binary)
{
    __asm__ volatile ("outb %0, %1" : : "a"(binary), "Nd"(port));
}


void print(char msg[], int down) // printing
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

    if (down == 1) // so that typing doesnt make a new line every letter
    {
        pos = (pos / 80 + 1) * 80;
    }
}

void kernel_main(void)
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
    volatile char *screen = (volatile char *)0xB8000; // VGA
    clear();

    print("               _", 1);
    print(" __      _____| | ___ ___  _ __ ___   ___", 1);
    print(" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\", 1);
    print("  \\ V  V /  __/ | (_| (_) | | | | | |  __/", 1);
    print("   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|", 1);
    print("if you are seeing this message XINL booted correctly with no error.", 1);
    print("> ", 0);
    int start = pos;
    int held_shift = 0;
    int count = 0;
    int numb = 0;
    char line[10];
    int cl = 0;
    set_keys();

    while (1 == 1) // keyboard workin ( ^ :
    {
        while ((inb(0x64) & 1) == 0)
        {
            count = count + 1;
            if (count == 10000000)
            {
                count = count - 10000000;
                if (numb == 0)
                {
                    numb = 1;
                    *(screen + pos * 2) = '_';
                    *(screen + pos * 2 + 1) = 0x0F;
                }
                else if (numb == 1)
                {
                    numb = 0;
                    *(screen + pos * 2)  = ' ';
                    *(screen + pos * 2 + 1) = 0x0F;
                }
                
            }
        }
        *(screen + pos * 2) = ' ';
        *(screen + pos * 2 + 1) = 0x0F;
        unsigned char ur = inb(0x60); // (UnReadable)

        if (ur == 0x2A || ur == 0x36) // shift down
        {
            held_shift = 1;
        }
        else if (ur == 0xAA || ur == 0xB6) // shift up
        {
            held_shift = 0;
        }
        else if ((ur & 0x80) == 0)
        {
            if (ur == 0x0E)
            {
                if (pos > start)
                {
                    if (cl > 0)
                    {
                        cl = cl - 1;   
                    }
                    pos = pos - 1;      // for backspace
                    *(screen + pos * 2) = ' ';
                    *(screen + pos * 2 + 1) = 0x0F;
                }
            }
            else if (ur == 0x1C)
            {
                line[cl] = '\0';
                if (line[0] == 'c' && line[1] == 'l' && line[2] == 'e' && line[3] == 'a' && line[4] == 'r' && line[5] == '\0')
                {
                    clear();
                    pos = 0;
                    print("> ", 0);
                    start = pos;
                }
                else
                {
                pos = (pos / 80 + 1) * 80;
                print("> ", 0);
                start = pos;
                }
                cl = 0;
            }
            else
            {
                char letter;
                if (held_shift == 1)
                {
                    letter = shift_keys[ur];
                }
                else
                {
                    letter = keys[ur];
                }
                if (letter != 0)
                {
                    char box[2];
                    box[0] = letter;
                    box[1] = '\0';
                    print(box, 0);
                    if (cl < 10)
                    {
                       line[cl] = letter;
                       cl = cl + 1;  
                    }
                
                }
            }
        }
    }
}
