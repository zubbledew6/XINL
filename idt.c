struct IDTEntry {
   unsigned short offset_low;
   unsigned short selector;
   unsigned char zero;
   unsigned char type;
   unsigned short offset_high;
}__attribute__((packed));
struct IDTEntry idt[256];
