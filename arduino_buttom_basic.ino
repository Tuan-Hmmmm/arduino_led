int ledr=8;
int buttom=7;
void setup()
{
  pinMode(ledr, OUTPUT);
  pinMode(buttom, INPUT);
}
void loop()
{
  int value=digitalRead(buttom);
  if (value==LOW)
  {
    digitalWrite(ledr, 1);
  }
  else if (value==HIGH)
  {
    digitalWrite(ledr, 0);
  }
}