#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
typedef struct servo {
  int readServo, highLimit, lowLimit;
} servoStruct;
Servo servohori;
servoStruct servohoriStruct;
Servo servoverti;
servoStruct servovertiStruct;
char auth[] = "Oqb1NiAtT1h3cmZqpdWnWNylVcInOeum";
char ssid[] = "Fimfilm";
char pass[] = "mannyfilmmy";
const byte ldrtopl = 33, ldrtopr = 34, ldrbotl = 35, ldrbotr = 36, servoh = 4, servol = 2;
const byte voltagePin = 32;
unsigned int startTime = 0;
void setup ()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  initServo();
  startTime = millis();
}

void loop()
{
  Blynk.run();
  controlServo();
  /*for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servohori.write(pos);    // tell servo to go to position in variable 'pos'
    servoverti.write(pos);
    delay(15);             // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servohori.write(pos);    // tell servo to go to position in variable 'pos'
    servoverti.write(pos);
    delay(15);             // waits 15ms for the servo to reach the position
  }*/
  
  if (millis() - startTime > 3000) {
    Blynk.virtualWrite(V0, readVoltage());
    startTime = millis();
  }
}
