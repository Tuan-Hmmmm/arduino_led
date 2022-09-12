#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int lightsensor=A0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("LIGHT MEASURE : " );
}
void loop()
{
  int tmp=analogRead(lightsensor);
  lcd.setCursor(5,1);
  lcd.print(tmp);
  Serial.println(tmp);
  
}

  