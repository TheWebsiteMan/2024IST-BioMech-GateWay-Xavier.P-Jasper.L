//remember to fix joystick with a new var for the x then check that for y then print 
//only if need neutral debug

static unsigned int myButton = 3;

void setup() {
  Serial.begin(9600);
  pinMode(myButton, INPUT);
}

void loop() {
  Serial.print("myButton:");
  Serial.println(digitalRead(myButton));
}