
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int echo = 7;     // chân echo của HC-SR04
const int trig = 8;
const int speaker=6;
void setup()
{
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT); // chân echo sẽ nhận tín hiệu
    pinMode(speaker, OUTPUT);
    lcd.begin(16,2);
    lcd.setCursor(3,0);
    lcd.print("DISTANCE: " );

}
void loop()
{
  float duration;
  float distance;
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 1);
  duration = pulseIn(echo,HIGH); 
  distance = duration/2/29.412;
  lcd.setCursor(5,1);
  lcd.print(distance);
  Serial.println(distance);
  if (distance > 200)
  {
    tone(speaker, 1000, 10000);
  }
  else 
  {
    noTone(speaker);
  }
 }