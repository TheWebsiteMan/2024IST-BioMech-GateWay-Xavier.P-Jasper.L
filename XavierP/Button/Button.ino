//remember to fix joystick with a new var for the x then check that for y then print 
//only if need neutral debug
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08
#include <Keyboard.h>
char ctrlKey = KEY_LEFT_CTRL;
static unsigned int myButtonA = 2;
static unsigned int myButtonB = 4;
static unsigned int myButtonSt = 7;
static unsigned int myButtonSe = 8;
int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int command = COMMAND_NO;

void setup() {
  Serial.begin(9600);
  Serial.print("working");
  pinMode(myButtonA, INPUT);
  pinMode(myButtonB, INPUT);
  pinMode(myButtonSt, INPUT);
  pinMode(myButtonSe, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(2) == HIGH) {
    Keyboard.press('z');
  }
  else {
  Keyboard.release('z');
  }
  if (digitalRead(4) == HIGH) {
    Keyboard.press('x');
  }
  else {
  Keyboard.release('x');
  }
  if (digitalRead(7) == HIGH) {
    Keyboard.press('c');
  }
  else {
  Keyboard.release('c');
  }
  if (digitalRead(8) == HIGH) {
    Keyboard.press('v');
  }
  else {
  Keyboard.release('v');
  }
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // converts the analog value to commands
  // reset commands
  command = COMMAND_NO;

  // check left/right commands
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;

  // check up/down commands
  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS

  // print command to serial and process command
  if (command & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    // TODO: add your task here
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    // TODO: add your task here
  }

  if (command & COMMAND_UP) {
    Serial.println("COMMAND UP");
    // TODO: add your task here
  }

  if (command & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    // TODO: add your task here
  }

  Serial.print("Buttons: A:");
  Serial.print(digitalRead(myButtonA));
  Serial.print(" B:");
  Serial.print(digitalRead(myButtonB));
  Serial.print(" St:");
  Serial.print(digitalRead(myButtonSt));
  Serial.print(" Se:");
  Serial.println(digitalRead(myButtonSe));
  delay(50);
}