#include <RadioHead.h>
#include <RH_ASK.h>
#include <Wire.h>
#include <SPI.h>

const int MPU = 0x68; // MPU6050 I2C address
int16_t acc_x, acc_y, acc_z; // taking varialble for storing input

RH_ASK driver;

void setup() 
{
  driver.init();  //initialisation for transmitter
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
}

void loop() {
  
  const char *a = "fast";
  const char *b = "slow";
  const char *c = "stop";
  const char *d = "right";
  const char *e = "left";
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); 
  
  acc_x = (Wire.read() << 8 | Wire.read());
  acc_y = (Wire.read() << 8 | Wire.read());
  acc_z = (Wire.read() << 8 | Wire.read());

  // taking refrence for acc_x and acc_y as 0 
  if(acc_x > 0.2 && acc_x <4) // 0.2 is taken as precaution
  {
   driver.send((uint8_t *)b, strlen(a));
   driver.waitPacketSent(); 
  }
  
  if(acc_x > 4.2 && acc_x <9) // 4.2 is taken as precaution
  {
   driver.send((uint8_t *)a, strlen(b));
   driver.waitPacketSent(); 
  }
   
   if(acc_x > 0 && acc_x <0.2)
  {
   driver.send((uint8_t *)c, strlen(c));
   driver.waitPacketSent(); 
  }

  if(acc_y>0)
  {
    driver.send((uint8_t *)d, strlen(d))
    driver.waitPacketSent(); 
  }

//    if(acc_y < 0)
//  {
//    driver.send((uint8_t *)e, strlen(e))
//    driver.waitPacketSent(); 
//  }
  Serial.print("x ");  
  Serial.print(acc_x);  
  Serial.print(" y");  
  Serial.print(acc_y);  
  Serial.print(" z ");  
  Serial.println(acc_z); // for printing accelaration values for in x,y,z direction
}




  
