#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 16

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

#include "../generic/common.h"

#endif /* Pins_Arduino_h */

 // pulse output from the module
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
void setup()
{
   Serial.begin(921600);
   pinMode(D9, INPUT);
   //Interrupt 0 is digital pin 2
   //Triggers on Falling Edge (change from HIGH to LOW)
   attachInterrupt(0, counter, FALLING);
   // Initialize
   pulses = 0;
   rpm = 0;
   timeold = 0;
}
void loop()
{
   if (millis() - timeold >= 1000) {
      //Don't process interrupts during calculations
      detachInterrupt(0);
      digitalWrite(D9, digitalRead(D9));
      rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses*100;
      timeold = millis();
      pulses = 0;
      Serial.print("RPM = ");
      Serial.println(rpm,DEC);
      //Restart the interrupt processing
      attachInterrupt(0, counter, FALLING);
   double value=analogRead(A0);
  Serial.println(analogRead(A0));
  if(value>=600){
    Serial.println("use less brake");
    count++;
  }
   
 if(count>5)
    {
    Serial.print("above permitted level");
    count=0;
    delay(10000);
    }     
  
  
  delay(1000);
   }
}
