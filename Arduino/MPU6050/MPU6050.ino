#include<Wire.h>
#include <RadioHead.h>
#include <RH_ASK.h>
#include <SPI.h>


// six codes are being used to drice the bot
// "0" is for halt
// "1" is for forward slow
// "2" is for forward fast
// "3" is for backward slow
// "4" is for backward fast
// "5" is for right
// "6" is for left




const int add = 0x68;
int16_t   acc_x,acc_y;
int count = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Wire.begin();
Wire.beginTransmission(add);
Wire.write(0x6B);
Wire.write(0x00);
Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(add);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(add,3*2,true);
acc_x = Wire.read()<<8 | Wire.read();
acc_y = Wire.read()<<8 | Wire.read();
acc_x = acc_x*0.2;
acc_y = acc_y * 0.5;

if((3200 < acc_x && acc_x < 3320) && (acc_y < 510 && acc_y > 380))
{
  Serial.print("stop");
  const char *a = "0";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }
  
}

else if((750 < acc_x && acc_x < 3180) && (acc_y < 570 && acc_y > 390))
{
  Serial.print("turn right");
  const char *a = "5";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }

}

else if((-30 < acc_x && acc_x < 3180) && (acc_y < 390 && acc_y > 220))
{
  Serial.print("turn left");
  const char *a = "6";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }

}

else if((2900 < acc_x && acc_x < 3200) && (acc_y < -1700 && acc_y > -4500))
{
  Serial.print("move reverse slowly");
  const char *a = "3";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }

}

else if((1340 < acc_x && acc_x < 2350) && (acc_y < -5200 && acc_y > -7500))
{
  Serial.print("move reverse fast");
  const char *a = "4";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }

}

else if((2700 < acc_x && acc_x < 3190) && (acc_y < 4200 && acc_y > 2120))
{
  Serial.print("move forward slowly");
  const char *a = "1";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }

}

else if((420 < acc_x && acc_x < 2220) && (acc_y < 8200 && acc_y > 6000))
{
  Serial.print("move forward fast");
  const char *a = "2";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
  }
}

else
{
   Serial.print("garbage");
   const char *a = "0";
   driver.send((uint8_t *)a, strlen(a));
   driver.waitPacketSent();
   {
     Serial.print("sucess");
   }
   
}

Serial.print("x ");
Serial.print(acc_x);
Serial.print("  y ");
Serial.println(acc_y);
//Serial.print("  count");
//Serial.println(count);
count  = count + 1;
if(count > 40)
{
  exit(0);
}

delay(500);
}
