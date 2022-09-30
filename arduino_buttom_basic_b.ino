int ledr=8;
int buttom=7;
 int count =0;
void setup()
{
  Serial.begin(9600);
  pinMode(ledr, OUTPUT);
  pinMode(buttom, INPUT);
  digitalWrite(ledr, 0);
}
void loop()
{
  int value=digitalRead(buttom);
  if (value==LOW)
{
 delay(250);
  count++;
  }
  if (count%2!=0)
  {
    digitalWrite(ledr, 1);
  }
  else if (count%2==0)
  {
    digitalWrite(ledr, 0);
  }
  Serial.println(count);
 
}