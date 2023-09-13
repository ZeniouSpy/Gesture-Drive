const int ena = 3;
const int fir = 4;
const int las = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ena,OUTPUT);
pinMode(fir,OUTPUT);
pinMode(las,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(fir,HIGH);
digitalWrite(las,LOW);
analogWrite(ena,200);
delay(5000);
analogWrite(ena,100);
delay(5000);
analogWrite(ena,10);
delay(5000);

}
