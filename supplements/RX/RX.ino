#include <RadioHead.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile


// using four motors 
// m1ena(3) m2ena(6) m3ena(9) m4ena(11) are the enable for front right, front left, back left, back right motors respectively
// inp2(2)and inp4(4) for front right
// inp5(5)and inp7(7) for front left
// inp8(8)and inp10(10) for back right
// inp12(12)and inp13(13) for back left



RH_ASK driver;

char buf[4] = "fast";
char str[4];
void setup()
{
    driver.init();
    Serial.begin(9600);
    pinMode(m1ena,OUTPUT);
    pinMode(m2ena,OUTPUT);
    pinMode(m3ena,OUTPUT);
    pinMode(m4ena,OUTPUT);
    pinMode(inp2,OUTPUT);
    pinMode(inp4,OUTPUT);
    pinMode(inp5,OUTPUT);
    pinMode(inp7,OUTPUT);
    pinMode(inp8,OUTPUT);
    pinMode(inp10,OUTPUT);
    pinMode(inp12,OUTPUT);
    pinMode(inp13,OUTPUT);
}


void loop()
{
    uint8_t buf[4];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
//      Serial.print("Message received: ");
//      Serial.println((char*)buf);   
        if(char(buf[0])== '0')
        {
          digitalWrite(2,LOW);
          digitalWrite(4,LOW);
                       
        }



          
    }
}
