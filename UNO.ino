#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(3,4);


int encoder_pin = 2; // pulse output from the module
static int count=0; 
unsigned int rpm; // rpm reading
volatile byte pulses; // number of pulses
unsigned long timeold;
// number of pulses per revolution
// based on your encoder disc
unsigned int pulsesperturn = 12;
void counter()
{
   //Update count 
   pulses++;
}

void setup(){
	
	Serial.begin(9600);
	ArduinoUno.begin(4800);
   pinMode(encoder_pin, INPUT);
   //Interrupt 0 is digital pin 2
   //Triggers on Falling Edge (change from HIGH to LOW)
   attachInterrupt(0, counter, FALLING);
   // Initialize
   pulses = 0;
   rpm = 0;
   timeold = 0;

}

void loop(){
	
	while(ArduinoUno.available()>0){
   if (millis() - timeold >= 1000) {
      //Don't process interrupts during calculations
      detachInterrupt(0);
      rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
      timeold = millis();
      pulses = 0;
      Serial.print("RPM = ");
      Serial.println(rpm,DEC);
      //Restart the interrupt processing
      attachInterrupt(0, counter, FALLING);
	}
	}
delay(30);
}
