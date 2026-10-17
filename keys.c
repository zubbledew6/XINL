char keys[128];
char shift_keys[128];

void set_keys(void)
{
    int i;
    for (i = 0; i < 128; i++)
    {
        keys[i] = 0;
        shift_keys[i] = 0;
    }

    keys[0x02] = '1';
    keys[0x03] = '2';
    keys[0x04] = '3';
    keys[0x05] = '4';
    keys[0x06] = '5';
    keys[0x07] = '6';
    keys[0x08] = '7';
    keys[0x09] = '8';
    keys[0x0A] = '9';
    keys[0x0B] = '0';
    keys[0x0C] = '-';
    keys[0x0D] = '=';

    keys[0x10] = 'q';
    keys[0x11] = 'w';
    keys[0x12] = 'e';
    keys[0x13] = 'r';
    keys[0x14] = 't';
    keys[0x15] = 'y';
    keys[0x16] = 'u';
    keys[0x17] = 'i';
    keys[0x18] = 'o';
    keys[0x19] = 'p';
    keys[0x1A] = '[';
    keys[0x1B] = ']';

    keys[0x1E] = 'a';
    keys[0x1F] = 's';
    keys[0x20] = 'd';
    keys[0x21] = 'f';
    keys[0x22] = 'g';
    keys[0x23] = 'h';
    keys[0x24] = 'j';
    keys[0x25] = 'k';
    keys[0x26] = 'l';
    keys[0x27] = ';';
    keys[0x28] = '\'';
    keys[0x29] = '`';

    keys[0x2B] = '\\';
    keys[0x2C] = 'z';
    keys[0x2D] = 'x';
    keys[0x2E] = 'c';
    keys[0x2F] = 'v';
    keys[0x30] = 'b';
    keys[0x31] = 'n';
    keys[0x32] = 'm';
    keys[0x33] = ',';
    keys[0x34] = '.';
    keys[0x35] = '/';

    keys[0x39] = ' ';

    shift_keys[0x02] = '!';
    shift_keys[0x03] = '@';
    shift_keys[0x04] = '#';
    shift_keys[0x05] = '$';
    shift_keys[0x06] = '%';
    shift_keys[0x07] = '^';
    shift_keys[0x08] = '&';
    shift_keys[0x09] = '*';
    shift_keys[0x0A] = '(';
    shift_keys[0x0B] = ')';
    shift_keys[0x0C] = '_';
    shift_keys[0x0D] = '+';

    shift_keys[0x10] = 'Q';
    shift_keys[0x11] = 'W';
    shift_keys[0x12] = 'E';
    shift_keys[0x13] = 'R';
    shift_keys[0x14] = 'T';
    shift_keys[0x15] = 'Y';
    shift_keys[0x16] = 'U';
    shift_keys[0x17] = 'I';
    shift_keys[0x18] = 'O';
    shift_keys[0x19] = 'P';
    shift_keys[0x1A] = '{';
    shift_keys[0x1B] = '}';

    shift_keys[0x1E] = 'A';
    shift_keys[0x1F] = 'S';
    shift_keys[0x20] = 'D';
    shift_keys[0x21] = 'F';
    shift_keys[0x22] = 'G';
    shift_keys[0x23] = 'H';
    shift_keys[0x24] = 'J';
    shift_keys[0x25] = 'K';
    shift_keys[0x26] = 'L';
    shift_keys[0x27] = ':';
    shift_keys[0x28] = '"';
    shift_keys[0x29] = '~';

    shift_keys[0x2B] = '|';
    shift_keys[0x2C] = 'Z';
    shift_keys[0x2D] = 'X';
    shift_keys[0x2E] = 'C';
    shift_keys[0x2F] = 'V';
    shift_keys[0x30] = 'B';
    shift_keys[0x31] = 'N';
    shift_keys[0x32] = 'M';
    shift_keys[0x33] = '<';
    shift_keys[0x34] = '>';
    shift_keys[0x35] = '?';

    shift_keys[0x39] = ' ';
}
