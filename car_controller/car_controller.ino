#include<Servo.h>

Servo carServo;

int servoPotPin = 0;
int servoPotValue;
int speedPotPin = 1;
int inputPin1=2;
int inputPin2=3;
int motorSpeed=0;
int enablePin=5;

void setup()
{
  carServo.attach(9);
  pinMode(inputPin1,OUTPUT);
  pinMode(inputPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);
}

void loop()
{
  servoPotValue=analogRead(servoPotPin);
  servoPotValue=map(servoPotValue, 0, 1023, 0, 180);
  carServo.write(servoPotValue);
  delay(15);
  
  motorSpeed=analogRead(speedPotPin);
  motorSpeed=map(motorSpeed, 0, 1023, 0, 255);
  analogWrite(enablePin,motorSpeed);
  
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
}t
