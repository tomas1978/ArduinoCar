#include<Servo.h>

Servo carServo;

int servoPotPin = 0;
int servoPotValue;
int inputPin1=2;
int inputPin2=3;

void setup()
{
  carServo.attach(9);
  pinMode(inputPin1,OUTPUT);
  pinMode(inputPin2,OUTPUT);
}

void loop()
{
  servoPotValue=analogRead(servoPotPin);
  servoPotValue=map(servoPotValue, 0, 1023, 0, 180);
  carServo.write(servoPotValue);
  delay(15);
  
  digitalWrite(inputPin1,HIGH);
  digitalWrite(inputPin2,LOW);
  delay(2000);
  
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,LOW);
  delay(1000);
  
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,HIGH);
  delay(2000);
  
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,LOW);
  delay(1000);
}
