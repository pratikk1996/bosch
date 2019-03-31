#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

static int count=0;
char auth[] = "20cf656c8624408f9307a418b126df86";
char ssid[] = "Technical Board IIT Guwahati";
char pass[] = "gymkhana";
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  
  Blynk.run();
  double value=analogRead(A0);
  Serial.println(analogRead(A0));
  if(value>=600){
    Serial.println("use less brakes!");
    count++;
  }
   
 if(count>5)
    {
    Serial.println("above permitted level");
    count=0;
    delay(50000);
    }     
  
  
  delay(3000);
}
 
