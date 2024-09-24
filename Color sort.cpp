#include <Servo.h>
//Color sensor
#define S0 A3
#define S1 A4
#define S2 A1
#define S3 A2
#define sensorOut A0
Servo topServo;
Servo midRight;
Servo midLeft;
Servo bottomupperRight;
Servo bottomlowerRight;
Servo bottomlowerLeft;
Servo bottomupperLeft;
Servo TopTop;
int frequency = 0;
int color=0;


//BT
byte Incoming_Data = 0;


byte purple = 0;
byte pink = 0;


void setup() {
  //Sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  topServo.attach(11); 
  midRight.attach(9);
  bottomlowerRight.attach(8);
  midLeft.attach(6); // Right
  bottomupperRight.attach(7);
  bottomlowerLeft.attach(5); 
  bottomupperLeft.attach(10);
  TopTop.attach(4);


  //BT
  Serial.begin(9600);     	//Sets the data rate in bits per second (baud) for serial data transmission

}
void loop() {
  //BT
  if(Serial.available() > 0)  
  {
	Incoming_Data = Serial.read();  //Read the incoming data and store it into variable Incoming_value
   	 
    
	if((int)Incoming_Data == 101)      	//Checks whether value of (int)Incoming_value is equal to 101.
	{
  	delay(200);
  	TopTop.write(50);
  	delay(5000);
  	topServo.write(55);
  	delay(500);
  	midLeft.write(55);
  	delay(500);
  	bottomlowerLeft.write(55);
  	delay(500);
 	 
	}



else if((int)Incoming_Data == 102)   //Checks whether value of (int)Incoming_value is equal to 102.
	{
      	delay(200);
      	TopTop.write(160);
      	delay(5000);
	}

	if ((int)Incoming_Data == 110)
	{
 	 
	}
  }


 
 
 //half loop, for sensor til at bevæge sig frem og tilbage
delay(200);
TopTop.write(160);
delay(500);
TopTop.write(80);
delay(500);
                       	 
 //Sensor
  color = readColor();
  delay(500);  
  switch (color) {
	case 1:
	TopTop.write(50);
   
	break;
	case 2:
	TopTop.write(50);
    
	break;
	
	case 0:
	break;

    
  }
delay(1000);
  TopTop.write(160);
  delay(100);
  topServo.write(90);
  delay(100);
  midLeft.write(90);
  delay(100);
  midLeft.write(90);
  delay(100);
  midRight.write(90);
  delay(100);
  bottomlowerRight.write(90);
  delay(100);
  bottomupperRight.write(90);
  delay(100);
  bottomlowerLeft.write(90);
  delay(100);
  bottomupperLeft.write(90);
  delay(100);




//this is Brown
if (color == 1)
{
 topServo.write(55);
  delay(500);
  midLeft.write(55);
  delay(500);
  bottomlowerLeft.write(55);
 delay(500);
 
  topServo.write(90);
  delay(500);
  topServo.write(55);
  delay(500);
 
  midLeft.write(90);
  delay(500);
  midLeft.write(55);
  delay(500);
 
  bottomlowerLeft.write(90);
 delay(500);
 bottomlowerLeft.write(55);
 delay(200);

  brown++;
}

int RedVal;
int GreenVal;
int BlueVal;

// Custom Function - readColor()
int readColor() {

  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  RedVal= frequency;
  





  Serial.println((int)purple);
  Serial.print('|');
  Serial.println((int)pink);
  Serial.print('|');
  Serial.println((int)green);
  Serial.print('|');
  
  Serial.print(RedVal);//printing RED color frequency
  Serial.print('|');
 
 
  if(G<=127 && G>=113 && B<=89 &B>=74 && R<=70 & R>=58)
  {
	color = 8; // Red
  }
 
  if(G<=90 && G>75 && B<=77 && B>=52 && R<=52 & R>=45)
  {
	color = 7; // Orange
  }
 
  return color;
  }


byte Incoming_Data = 0;

byte purple = 0;
byte pink = 0;
byte green = 0;
byte red = 0;
byte brown = 0;
byte orange = 0;
byte blue = 0;
byte yellow = 0;

void setup() 
{
  Serial.begin(9600);         
  pinMode(8, OUTPUT);       
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_Data = Serial.read();         
    
    if((int)Incoming_Data == 101)          
    {
      digitalWrite(8, HIGH); 
    } 
    else if((int)Incoming_Data == 102)   
    {
      digitalWrite(8, LOW);
    }
  } 

  Serial.println((int)purple);
  Serial.println('|');
  Serial.println((int)pink);
  Serial.println('|');
  Serial.println((int)green);
  Serial.println('|');
  Serial.println((int)red);
  Serial.println('|');
  Serial.println((int)brown);
  Serial.println('|');
  Serial.println((int)orange);
  Serial.println('|');
  Serial.println((int)blue);
  Serial.println('|');
  Serial.println((int)yellow);
  Serial.println('|');
}
const int s0 = A3;  
const int s1 = A4;  
const int s2 =A1;  
const int s3 = A2;  
const int out = A0;   
// values
int red = 0;  
int green = 0;  
int blue = 0;  

void setup()   
{  
  Serial.begin(9600);
 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
 
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}
 
void loop()
{  
  color();
  Serial.println("RED");  
  Serial.println(red, DEC);  
  Serial.println(" GREEN ");  
  Serial.println(green, DEC);  
  Serial.println(" BLUE ");  
  Serial.println(blue, DEC);  

  if (red < blue && red < green && red < 20)
  {  
  	if (red <=10 && green <=10 && blue <=10){
 	Serial.println("WHILE");   
  } else{
   Serial.println(" - (Red Color)");
  }
}  
else if (blue < red && blue < green)   
  {  
  	if (red <=10 && green <=10 && blue <= 10){
 	Serial.println("WHILE");  
  }else {
   Serial.println(" - (Blue Color)");   }
  }  
  else if (green < red && green < blue)  
  {  
	if (red <= 10 && green <=10 && blue <= 10){
 	Serial.println("WHILE");   
  } else{
   Serial.println(" - (Green Color)");  }
  }  
  else{
  Serial.println();  
  }
  delay(1000);
}


void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
#define S0 A3
#define S1 A4
#define S2 A1
#define S3 A2
#define sensorOut A0

int frequency = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
 
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,72,255,0);
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);


  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,90,255,0);
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,70,255,0);
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");
  delay(100);
}
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

