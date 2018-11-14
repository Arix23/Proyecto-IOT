#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int digitalPin = 16; // sensor Humedad
int dservo= D5; //Servo
const int buzzer = 4; 
int LED=5; //Pin del Led

#include <Servo.h> // including servo library-
Servo servo_1; // Giving name to servo.


char auth[] = "b47295ebc2864a97a98450c62c534da0";
char ssid[] = "AndroidAP";
char pass[] = "quimica1234";
void setup() {
  pinMode(digitalPin, INPUT);
  servo_1.attach(D5); // Attaching Servo to D3
  servo_1.write(0);
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
  // put your setup code here, to run once:
  Blynk.begin(auth,ssid,pass);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
    int sensorValue = analogRead(A0);   // read the input on analog pin 0
  int enable = digitalRead(15);

  /*
   * High == Dry0
   * Low == Wet
   */

   if(!enable){
    sensorValue = 0;
   }
  if (sensorValue>500){
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
  else if(sensorValue<=500){    
    Serial.println("Wet");
    digitalWrite(LED,LOW);
  }
  else{
    Serial.println("Error");
  }

  Serial.println(sensorValue);
  Serial.println(digitalRead(16)); 

  delay(1000); 
  digitalRead(digitalPin);
  Serial.println(digitalRead(D0));

}
