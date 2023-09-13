#include <RadioHead.h>
#include <SPI.h>
#include <RH_ASK.h>

RH_ASK driver;

const int fl1 = 6; // for first arduino
const int fl2 = 9;
const int fr1 = 10;
const int fr2 = 11;
const int bl1 = 6; // for second arduino
const int bl2 = 9;
const int br1 = 10;
const int br2 = 11;
void setup() {
  // put your setup code here, to run once:
driver.init();
Serial.begin(9600);
pinMode(fl1,OUTPUT);
pinMode(fl2,OUTPUT);
pinMode(fr1,OUTPUT);
pinMode(fr2,OUTPUT);
pinMode(bl1,OUTPUT);
pinMode(bl2,OUTPUT);
pinMode(br1,OUTPUT);
pinMode(br2,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
uint8_t buf[4];
uint8_t buflen = sizeof(buf);
if(driver.recv(buf, &buflen))
{
 int i;
 str1 = (char*)buf
 if(str1.equals(fast))
 {
  analogWrite(bl1,255);
  analogWrite(bl2,0);  
 }
 if(str1.equals(slow))
 {
  analogWrite(bl1,170);
  analogWrite(bl2,0);  
 }
 if(str1.equals(slow))
 {
  analogWrite(bl1,0);
  analogWrite(bl2,0);  
 }

 if(str1.equals(fast))
 {
  analogWrite(bl1,255);
  analogWrite(bl2,0);  
 }  

}

}
