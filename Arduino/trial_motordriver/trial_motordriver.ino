const int ena1 = 3;
const int ena2 = 6;
const int ena3 = 9;
const int ena4 = 11;
const int inp1 = 2;
const int inp2 = 4;
const int inp3 = 5;
const int inp4 = 7;
const int inp5 = 8;
const int inp6 = 10;
const int inp7 = 12;
const int inp8 = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(ena1,OUTPUT);
pinMode(ena2,OUTPUT);
pinMode(ena3,OUTPUT);
pinMode(ena4,OUTPUT);
pinMode(inp1,OUTPUT);
pinMode(inp2,OUTPUT);
pinMode(inp3,OUTPUT);
pinMode(inp4,OUTPUT);
pinMode(inp5,OUTPUT);
pinMode(inp6,OUTPUT);
pinMode(inp7,OUTPUT);
pinMode(inp8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(inp1,HIGH);
digitalWrite(inp2,LOW);
analogWrite(ena1,255);
digitalWrite(inp3,HIGH);
digitalWrite(inp4,LOW);
analogWrite(ena2,255);
digitalWrite(inp5,HIGH);
digitalWrite(inp6,LOW);
analogWrite(ena3,255);
digitalWrite(inp7,HIGH);
digitalWrite(inp8,LOW);
analogWrite(ena4,255);
delay(5000);
}
