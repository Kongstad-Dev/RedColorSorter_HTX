#include <Servo.h>
 
Servo myservo;  
 
int pos = 0;	// variable to store the servo position

const int trackingPin = 8;
const int ledPin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(trackingPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(2);  

}
 
void loop()
{
  for(pos = 0; pos <= 180; pos += 1)
  {                            	 
	myservo.write(pos);          	// tell servo to go to position in variable 'pos'
	delay(15);                  	 
  }
  for(pos = 180; pos>=0; pos-=1)	 
  {                           	 
	myservo.write(pos);         	 
  }

  boolean val = digitalRead(trackingPin);
  if(val == HIGH)
  {
	digitalWrite(ledPin, LOW);
	Serial.println("Detect: 0");
  }
  else
  {
	digitalWrite(ledPin, HIGH);
	Serial.println("Detect: 180");
  }

  if (val == HIGH){pos = 0;}
  if (val == LOW) {pos = 180;}
}
