#include<Servo.h>
int servo=7;
int goc;
Servo s;
void setup()
{
Serial.begin(9600);
s.attach(servo);
}
void loop()
{
  for (goc=0;goc<=180;goc++)
  {
    s.write(goc);
    delay(12);
  }
  for (int goc=180;goc>=0;goc--)
  {
    s.write(goc);
    delay(12);
  }
  
}