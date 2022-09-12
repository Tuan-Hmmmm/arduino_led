#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("NHIET DO");
}
void loop()
{
  float x=analogRead(A0);
  float y=map(x,0,1024,0,5000);
  float z=y-495;
  float celcius=z/10;
  lcd.setCursor(5,1);
  lcd.print(celcius);
}