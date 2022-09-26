
int lightsensor=A0;
int piezzo=9;
const int echo = 7;     // chân echo của HC-SR04
const int trig = 8;
int ledr=5;
int ledg=6;
int ledy=4;
void setup()
 {
    Serial.begin(9600); 
    pinMode(lightsensor, INPUT);  
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT); 
    pinMode(piezzo, OUTPUT);
    pinMode(ledr, OUTPUT);
    pinMode(ledg, OUTPUT);
 
    pinMode(ledy, OUTPUT);
 }
void loop()
 {
    float duration;
    float distance;
    int value=analogRead(lightsensor);
    digitalWrite(trig, 0);
    delayMicroseconds(2);
    digitalWrite(trig, 1);
    delayMicroseconds(5);
    digitalWrite(trig, 1);
    duration = pulseIn(echo,HIGH); 
    distance = duration*0.034/2;
    {
    if (value<3)
    {
     digitalWrite(ledy, 1);
    }
    else 
    {
      digitalWrite(ledy, 0);
    }
    }

    if (distance<15)
    {
      tone(piezzo, 10000,50000);
      digitalWrite(ledr, 1);
      digitalWrite(ledg, 0);
    }
    else 
    {
      noTone(piezzo);
        digitalWrite(ledr, 0);
      digitalWrite(ledg, 1);
    }
    {Serial.println(distance);
    delay(500);
    }
  }
