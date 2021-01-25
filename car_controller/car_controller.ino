#include<Servo.h>

Servo carServo;

int servoPotPin = 0;
int servoPotValue;
int speedPotPin = 1;
int inputPin1=2;
int inputPin2=3;
int motorSpeed=0;
int enablePin=5;
int forwardButtonPin=8;
int stopButtonPin=7;
int reverseButtonPin=6;

void setup()
{
  Serial.begin(9600);
  carServo.attach(9);
  pinMode(inputPin1,OUTPUT);
  pinMode(inputPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);
  pinMode(forwardButtonPin, INPUT);
  pinMode(stopButtonPin, INPUT);
  pinMode(reverseButtonPin, INPUT);  
}

void stop() {
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,LOW);
}

void forward() {
  digitalWrite(inputPin1,HIGH);
  digitalWrite(inputPin2,LOW);
}

void reverse() {
  digitalWrite(inputPin1,LOW);
  digitalWrite(inputPin2,HIGH);
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

  
  if(digitalRead(forwardButtonPin)==HIGH)
    forward();
  if(digitalRead(stopButtonPin)==HIGH)
    stop();
  if(digitalRead(reverseButtonPin)==HIGH)
    reverse();
  delay(10);
}
