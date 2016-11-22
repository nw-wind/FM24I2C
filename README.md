# FM24I2C
Arduino library with interface for FM24C64 FRAM-I2C chip.

The main interface is:

```FM24I2C fm(int id)``` creates the object fm with I2C id of the chip.

```fm.pack(int address, void *data, int length)``` stores into FRAM at address your data of length bytes long.

```int fm.unpack(int address, void *data, int length)``` fetches from FRAM at address into your data of length bytes. Returns the number of bytes actually read. The success is then it returns the same amount as length parameter.

Also this library has some macros like:

```writeUnsignedLong(int address, unsigned long data)``` to store the unsigned long number at address of FRAM.

```unsigned long readUnsignedLong(int address)``` returns unsigned long number stored at address in FRAM.

I plan to add some more macros for other data types. They are not consuming the memory because are not function and looks like the follows.

```arduino
void inline writeUnsignedLong(int addr, unsigned long data) {
      pack(addr, (void*)&data, sizeof(unsigned long));
    } 
unsigned long inline readUnsignedLong(int addr) {
    unsigned long data;
    return unpack(addr, (void*)&data, sizeof(unsigned long)) == sizeof(unsigned long) ? data : 0UL;
}
```

The general purpose of this library was to store any data including structures without any serialization like the follows.

```arduino
...
struct mydata {
  int a;
  byte b;
  char s[80];
} mystr;
... some code here ...
fm.pack(0x0100,(void*)&mystr,sizeof(struct mydata));
... some code here ...
fm.unpack(0x0100,(void*)&mystr,sizeof(struct mydata));
...
```

Yours,
Sergio
