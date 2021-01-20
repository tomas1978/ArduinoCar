#include<Servo.h>

Servo carServo;

int servoPotPin = 0;
int servoPotValue;

void setup()
{
  carServo.attach(9);
}

void loop()
{
  servoPotValue=analogRead(servoPotPin);
  servoPotValue=map(servoPotValue, 0, 1023, 0, 180);
  carServo.write(servoPotValue);
  delay(15);
}
