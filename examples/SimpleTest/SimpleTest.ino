#include "FM24I2C.h"

FM24I2C fm(0x57);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  char str1[]="12345678901234567890";
  char str2[]="qwertyuiopasdfghjklzxcvbnm";
  int a1=0x00;
  int a2=0x40;
  fm.pack(a1,str1,strlen(str1)+1);
  delay(5);
  fm.pack(a2,str2,strlen(str2)+1);
  delay(5);
  char buf[80];
  fm.unpack(a2,buf,strlen(str2)+1);
  Serial.println(str2);
  fm.unpack(a1,buf,strlen(str1)+1);
  Serial.println(str1);
}

void loop() {
  // put your main code here, to run repeatedly:

}