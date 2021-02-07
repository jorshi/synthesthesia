#include "Adafruit_TCS34725.h"

#define inputButton 2

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  //Serial.println("Color View Test!");

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  pinMode(inputButton, INPUT_PULLUP);
}

void loop() {
  if (isButtonPressed(inputButton)) {
    tcs.setInterrupt(false); // turn on LED
    delay(50);
    readColour();
    
  } else {
    delay(10);
    tcs.setInterrupt(true); // turn off LED
  }
}

boolean isButtonPressed(int btnPin) {
  int buttonValue = digitalRead(btnPin);
  if (buttonValue == LOW) {
    return true;
  }
  return false;
}

void readColour() {
  float red, green, blue;
  tcs.getRGB(&red, &green, &blue);
  
  Serial.print(byte(red)); Serial.print(" ");
  Serial.print(byte(green)); Serial.print(" ");
  Serial.print(byte(blue)); Serial.println(" ");
}
