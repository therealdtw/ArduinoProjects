/*
 Created from the base of http://www.arduino.cc/en/Tutorial/Blink
 
*/
  
  // PIN to relay mapping
  static int RELAY_1 = 5;
  static int RELAY_2 = 6;
  static int RELAY_3 = 7;
  static int RELAY_4 = 2;
  static int RELAY_5 = 3;
  static int RELAY_6 = 4;
  static int RELAY_7 = 8;
  static int RELAY_8 = 9;

  static int RELAY_TEST = RELAY_1;
  
  static int DELAY = 1000;
  static int ON = LOW;
  static int OFF = HIGH;

void allOn(){
 
  digitalWrite(RELAY_1, ON);
  digitalWrite(RELAY_2, ON);
  digitalWrite(RELAY_3, ON);
  digitalWrite(RELAY_4, ON);
  digitalWrite(RELAY_5, ON);
  digitalWrite(RELAY_6, ON);
  digitalWrite(RELAY_7, ON);
  digitalWrite(RELAY_8, ON);
}

void allOff(){
  
  digitalWrite(RELAY_1, OFF);
  digitalWrite(RELAY_2, OFF);
  digitalWrite(RELAY_3, OFF);
  digitalWrite(RELAY_4, OFF);
  digitalWrite(RELAY_5, OFF);
  digitalWrite(RELAY_6, OFF);
  digitalWrite(RELAY_7, OFF);
  digitalWrite(RELAY_8, OFF);
}

// the setup function runs once when you press reset or power the board
void setup() {
  //setup serial communications through the USB
  Serial.begin(9600);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);
  pinMode(RELAY_6, OUTPUT);
  pinMode(RELAY_7, OUTPUT);
  pinMode(RELAY_8, OUTPUT);
  
  digitalWrite(LED_BUILTIN, OFF);


  allOff();

  Serial.println("Setup done.");
  //Serial.print("ON = ");
  //Serial.println(ON);
  //Serial.print("OFF = ");
  //Serial.println(OFF);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("void loop() { ... }");

  delay(DELAY);

  digitalWrite(RELAY_1, ON);
  delay(DELAY);
  digitalWrite(RELAY_1, OFF);
  digitalWrite(RELAY_2, ON);
  delay(DELAY);
  digitalWrite(RELAY_2, OFF);
  digitalWrite(RELAY_3, ON);
  delay(DELAY);
  digitalWrite(RELAY_3, OFF);
  digitalWrite(RELAY_4, ON);
  delay(DELAY);
  digitalWrite(RELAY_4, OFF);
  digitalWrite(RELAY_5, ON);
  delay(DELAY);
  digitalWrite(RELAY_5, OFF);
  digitalWrite(RELAY_6, ON);
  delay(DELAY);
  digitalWrite(RELAY_6, OFF);
  digitalWrite(RELAY_7, ON);
  delay(DELAY);
  digitalWrite(RELAY_7, OFF);
  digitalWrite(RELAY_8, ON);
  delay(DELAY);
  digitalWrite(RELAY_8, OFF);
  delay(DELAY);
}
