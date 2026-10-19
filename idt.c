struct IDTEntry {
   unsigned short offset_low;
   unsigned short selector;
   unsigned char zero;
   unsigned char type;
   unsigned short offset_high;
}__attribute__((packed));
struct IDTEntry idt[256];

void idtfill(int num, unsigned handler)
{
  // idt[num].offset_low = 
   idt[num].selector = 0x08;
   idt[num].zero = 0;
   idt[num].type = 0x8E;
 //  idt[num].offset_high = 
}
