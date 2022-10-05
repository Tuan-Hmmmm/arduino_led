#include <SoftwareSerial.h> //Thư viện sử dụng bất kỳ 2 chân digital nào để làm chân TX RX
SoftwareSerial mybluetooth(2,3); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)
#include <Servo.h>. 
char docgiatri; //Biến docgiatri kiểu char
int piezzo=4;
const int trigPin =13;
const int echoPin =12;
long duration;
int distance;
Servo myServo; 
void setup() 
{
  Serial.begin(9600);
  mybluetooth.begin(9600); //Kết nối Bluetooth với tốc độ baud là 9600
  myServo.attach(5);
  for (int i=6;i<=11;i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(piezzo, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() 
{
  if(mybluetooth.available() > 0) //Nếu tín hiệu của bluetooth lớn hơn 0, tức là đã kết nối OK
  {
    docgiatri = mybluetooth.read(); //Đọc các giá trị trên app được kết nối qua bluetooth và gán vào docgiatri
    Serial.print("Read value : ");      
    Serial.print(docgiatri); //in giá trị lên cổng Serial 
    Serial.print("--");
  
      if (docgiatri=='0')
      {
        for (int j=6;j<=11;j++)
        {
          digitalWrite(j, 0);
        }
        Serial.println("ALL LED OFF");
      }
      if (docgiatri == '1')
      {
          digitalWrite(6, 1);
          digitalWrite(11, 1);
          for (int i=7;i<=10;i++)
          {
            digitalWrite(i, 0);
          }  
          Serial.println("LED RED ON")  ;
          
      }
      if (docgiatri == '2')
      {
         digitalWrite(10, 1);
         digitalWrite(9, 1);
          digitalWrite(6, 0);
          digitalWrite(7, 0);
          digitalWrite(8, 0);
          digitalWrite(11, 0);
          Serial.println("LED YELLOW ON");
          
      }

    
      if (docgiatri == '3')
      {
         digitalWrite(10, 0);
         digitalWrite(9, 0);
          digitalWrite(6, 0);
          digitalWrite(7, 1);
          digitalWrite(8, 1);
          digitalWrite(11, 0);
          Serial.println("LED GREEN ON");
          
      }
      if (docgiatri=='4')
      {
        for (int j=11;j>=6;j--)
        {
          digitalWrite(j, 1);
        }
        Serial.println("ALL LED ON");
      }
      if (docgiatri=='5')
      {
         tone(piezzo, 10000, 50000);
         Serial.println("PIEZZO ON");
      }
      if (docgiatri=='6')
      {
        noTone(piezzo);
        Serial.println("PIEZZO OFF");
      }
      if (docgiatri=='7')
      {
        distance = calculateDistance();
        Serial.println("TURN ON ALERT");
        
         { if (distance<40)
          {
            tone(piezzo, 10000, 50000);
            Serial.println(distance);
          }
           else 
          {
            noTone(piezzo);
    
          }
        }
      }
      if (docgiatri=='8')
      {
       offcalDistance();
       Serial.println("TURN OFF ALERT");
      }
      if (docgiatri=='9')
      {
        int k=0;
        while (k<=3)
        {
          for (int t=0;t<=180;t++)
          {
            myServo.write(t);
            delay(20);
          }
          for (int t=180;t>=0;t--)
          {
            myServo.write(t);
            delay(20);
          }
          k++;

        }
        Serial.println("MOVE !");
      }
      if (docgiatri=='k')
      {
        myServo.write(0);
        Serial.println("STOP MOVE ");
      }
      
     

    }
    
  
}
int calculateDistance(){ 

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void offcalDistance()
{
   digitalWrite(trigPin, LOW);
   digitalWrite(trigPin, LOW); 
   noTone(piezzo);
}


