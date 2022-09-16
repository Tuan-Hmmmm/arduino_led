
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int speaker=6;
int gas_sensor=A0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("SAFETY");
}
void loop()
{
int tmp=analogRead(gas_sensor);
  Serial.println(tmp);
  delay(1000);
  if (tmp>=150)
  {
    tone(speaker,1000,10000);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("DANGEROUS !");
    lcd.setCursor(2,1);
    lcd.print("CON.GAS: ");
    lcd.print(tmp);  
  }
  else 
  {
    noTone(speaker);
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("SAFETY");
    lcd.setCursor(2,1);
    lcd.print("CON.GAS: ");
    lcd.print(tmp);            
   }
  }