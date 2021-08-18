#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

const int lightSensor = A0;
const int soundSensor = A1;

unsigned long garageOpenTime = 0;

int garageDoorOpen = 0;
unsigned int currTime = 0;
unsigned int diff = 0;
int openTooLong = 0;

const int timeThreshold = 60000;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  lcd.print("Hello!");

  Serial.begin(9600);
  delay (1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Light Sensor
  int lightSensorValue = analogRead(lightSensor);

  //Sound Sensor
  long soundSensorValue = 0;
  for(int i = 0; i < 32; i++)
  {
    soundSensorValue += analogRead(soundSensor);
  }
  soundSensorValue >>= 5;
  
  switch(garageDoorOpen){
    case 0:
        if (lightSensorValue > 200 && soundSensorValue >= 800)
        {
          garageOpenTime = millis();
          Serial.println("Garage Open!");
          Serial.println("Garage Open Time = "); 
          Serial.println(garageOpenTime);
          garageDoorOpen = 1;
          lcd.setCursor(0,1);
          lcd.println("Open!");
          delay(3000);
        }
        break;
      
    case 1:
      if(lightSensorValue < 200 && soundSensorValue >= 800)
      {
        Serial.println("Garage Closed!");
        garageDoorOpen = 0;
        currTime = 0;
        garageOpenTime = 0;
        openTooLong = 0;
        diff = 0;
        lcd.setCursor(0,1);
        lcd.print("Closed!");
        delay(3000);
        break;
      }
      delay(1);
      currTime = millis();
      diff = (currTime - garageOpenTime);

      if(diff > timeThreshold)
      {
        openTooLong = 1;
      }
      if(openTooLong == 1)
      {
        Serial.println("garage should be closed by now...");
        lcd.setCursor(0,1);
        lcd.print("Check garage");
        delay(30);
      }
      break;
  }

  delay(1);
  
}
