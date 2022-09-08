int led=9;
int lightsensor=A0;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int value=analogRead(lightsensor);
  Serial.println(value);
  if (value<300)
  {
    digitalWrite(led, 1);
  }
else 
{
  digitalWrite(led, 0);
}
}