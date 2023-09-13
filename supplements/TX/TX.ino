#include <RadioHead.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{

  driver.init();
  Serial.begin(9600);
}

void loop()
{
  const char *a = "abcd";
  driver.send((uint8_t *)a, strlen(a));
  driver.waitPacketSent();
  {
    Serial.print("sucess");
    delay(1000);
  }
}
