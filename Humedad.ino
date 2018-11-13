int digitalPin = 3; // sensor Humedad
int analogPin= 0; //Servo
const int buzzer = 4; 
int LED=5; //Pin del Led
int sensorValue = analogRead(A0);   // read the input on analog pin 0
#include <Servo.h> // including servo library-
Servo servo_1; // Giving name to servo.
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  servo_1.attach(0); // Attaching Servo to D3
  servo_1.write(0);
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
}

void loop() {

  /*
   * High == Dry0
   * Low == Wet
   */
  if (digitalRead(digitalPin)>0.75){
    Serial.println("Dry");
    servo_1.write(360); // Servo will move to 45 degree angle.
    delay (1000);
    servo_1.write(0); // Servo will move to 45 degree angle.
    delay (1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    Serial.println("Beep");
    digitalWrite(LED,HIGH);      
  
  }
  else if(digitalRead(digitalPin)<=0.75){    
    Serial.println("Wet");
     
  }
  else{
    Serial.println("Error");
  }

  Serial.println(sensorValue); 

  delay(1000);
}
