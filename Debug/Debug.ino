#include "Keyboard.h"
// use this option for OSX:
//char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux:

void setup() {

  Serial.begin(9600);
  Serial.print("working");
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  Keyboard.press('n');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}