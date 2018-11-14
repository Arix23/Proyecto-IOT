#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "bef93b8c05e34908947a688243fce19a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Android AP";
char pass[] = "quimica1234";



void setup()
{
  // Debug console
  Serial.begin(9600); 

  Blynk.begin(auth, ssid, pass);
   
}

void loop()
{
  Blynk.run();  
}
