#include "Wire.h"

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#ifndef _FM24I2C_H_
#define _FM24I2C_H_

class FM24I2C {
  private:
    int id;
  public:
    FM24I2C(int id_addr);
    ~FM24I2C();
    void pack(int addr, void* data, int len);     // Pack data into FRAM
    int unpack(int addr, void* data, int len);    // Unpack data from FRAM. Returns number of bytes read.
    void inline writeUnsignedLong(int addr, unsigned long data) {
      pack(addr, (void*)&data, sizeof(unsigned long));
    } 
    unsigned long inline readUnsignedLong(int addr) {
      unsigned long data;
      return unpack(addr, (void*)&data, sizeof(unsigned long)) == sizeof(unsigned long) ? data : 0UL;
    }
};

#endif