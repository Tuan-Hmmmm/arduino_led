
int ledr=5;
int ledg=6;
const int Pin=8;
int piezzo=7;
void setup() {
 pinMode(ledr, OUTPUT);
 pinMode(ledg, OUTPUT);
 pinMode(piezzo, OUTPUT);
 pinMode(Pin, INPUT);
Serial.begin(9600);
 }
 
void loop() {
 
  int value= digitalRead(Pin);
 if (value==HIGH)
 {
  digitalWrite(ledr, 1);
  digitalWrite(ledg, 0);
  tone(piezzo, 10000, 50000);
  Serial.println("ON-State");
 }
 else
 {
   digitalWrite(ledr, 0);
  digitalWrite(ledg, 1);
  noTone(piezzo);
  Serial.println("OFF-State");
 }
}  