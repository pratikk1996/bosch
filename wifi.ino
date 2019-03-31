#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D3,D4);

void setup(){
	Serial.begin(9600);
	NodeMCU.begin(4800);
	pinMode(D3,INPUT);
	pinMode(D4,OUTPUT);
}

void loop(){
	int i=10;
	NodeMCU.print(i);
	NodeMCU.println("\n");
	delay(300);
 }
