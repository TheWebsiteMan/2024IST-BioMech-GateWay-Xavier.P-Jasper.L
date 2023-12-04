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
static unsigned int myButtonA = 2;
static unsigned int myButtonB = 4;
static unsigned int myButtonSt = 7;
static unsigned int myButtonSe = 8;
int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis
int command = COMMAND_NO;

void setup() {
  Serial.begin(9600);
  Serial.println("working");
  pinMode(myButtonA, INPUT);
  pinMode(myButtonB, INPUT);
  pinMode(myButtonSt, INPUT);
  pinMode(myButtonSe, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
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
    Serial.println("LEFT");
    // TODO: add your task here
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("RIGHT");
    // TODO: add your task here
  }

  if (command & COMMAND_UP) {
    Serial.println("UP");
    // TODO: add your task here
  }

  if (command & COMMAND_DOWN) {
    Serial.println("DOWN");
    // TODO: add your task here
  }

  if (digitalRead(myButtonA) == 1) {
    Serial.println("A");
  }

  if (digitalRead(myButtonB) == 1) {
    Serial.println("B");
  }
  if (digitalRead(myButtonSe) == 1) {
    Serial.println("SELECT");
  }
  if (digitalRead(myButtonSt) == 1) {
    Serial.println("START");
  }

  delay(50);
}