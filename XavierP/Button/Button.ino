//remember to fix joystick with a new var for the x then check that for y then print 
//only if need neutral debug

static unsigned int myButtonA = 2;
static unsigned int myButtonB = 4;
static unsigned int myButtonSt = 7;
static unsigned int myButtonSe = 8;


void setup() {
  Serial.begin(9600);
  pinMode(myButtonA, INPUT);
  pinMode(myButtonB, INPUT);
  pinMode(myButtonSt, INPUT);
  pinMode(myButtonSe, INPUT);
}

void loop() {
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