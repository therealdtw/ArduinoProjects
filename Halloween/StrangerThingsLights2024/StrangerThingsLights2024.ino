/*
 Created from the base of http://www.arduino.cc/en/Tutorial/Blink
 
*/
  
  // RELAY_x to PIN mapping
  static int RELAY_1 = 5; 
  static int RELAY_2 = 6; 
  static int RELAY_3 = 7; 
  static int RELAY_4 = 2;
  static int RELAY_5 = 3;
  static int RELAY_6 = 4;

  static int RELAY_7 = 8;
  static int RELAY_8 = 9;
  /* Previously used to turn some LED's on and off.  Just left here for a reference
  static int RELAY_R = 10;
  static int RELAY_U = 11;
  static int RELAY_N = 12;
  */
  int relaysForCrazyTrain[] = {RELAY_1,RELAY_2,RELAY_3,RELAY_4,RELAY_5,RELAY_6,RELAY_7,RELAY_8};
  
  static int DELAY = 1000;
  static int ON = LOW;
  static int OFF = HIGH;

  static int SLEEP_TIME_SHORT = 147;
  static int SLEEP_TIME_MEDIUM = 267;
  static int SLEEP_TIME_LONG = 393;
  static int SLEEP_TIME_WARMUP = 1000;
  static long SLEEP_TIME_LOOP = 3000;

  static int CRAZY_TRAIN_LOOPS = 300;
  static int CRAZY_TRAIN_LOOP_DELAY = 47;

  boolean firstLoopDone = false;
  int thirteen = LOW;
  long randomNumber;
  long randomRelay;

void allOn(int sleep_delay){
 
  digitalWrite(RELAY_1, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_2, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_3, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_4, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_5, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_6, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_7, ON);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_8, ON);
  activity();
}

void allOff(int sleep_delay){
  
  digitalWrite(RELAY_1, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_2, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_3, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_4, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_5, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_6, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_7, OFF);
  activity();
  delay(sleep_delay);
  digitalWrite(RELAY_8, OFF);
  activity();
  delay(sleep_delay);
}

void activity(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10);
  digitalWrite(LED_BUILTIN, LOW);
}

void relay_close(int relay,int sleep_delay){
  digitalWrite(RELAY_1, ON);
  activity();    
  delay(SLEEP_TIME_SHORT);
}

void relay_open(int relay,int sleep_delay){
  digitalWrite(RELAY_1, OFF);
  activity();    
  delay(SLEEP_TIME_SHORT);
}


void blink_relay_1(){
  Serial.println("Action = blink_rely_1()");
  relay_open(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_close(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_open(RELAY_1,SLEEP_TIME_SHORT);
  relay_close(RELAY_1,SLEEP_TIME_SHORT);
  relay_open(RELAY_1,SLEEP_TIME_SHORT);
  relay_close(RELAY_1,SLEEP_TIME_LONG);
  relay_open(RELAY_1,SLEEP_TIME_SHORT);
  relay_close(RELAY_1,SLEEP_TIME_LONG);
  relay_open(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_close(RELAY_1,SLEEP_TIME_SHORT);
  relay_open(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_close(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_open(RELAY_1,SLEEP_TIME_SHORT);
  relay_close(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_open(RELAY_1,SLEEP_TIME_MEDIUM);
  relay_close(RELAY_1,SLEEP_TIME_SHORT);
}

void blink_crazy_train(){

     //crazy train
    // **********
    //(sizeof(CRAZY_TRAIN_LOOPS)/sizeof(int))
    Serial.print("Array size of relaysForCrazyTrain = ");
    Serial.println((sizeof(relaysForCrazyTrain)/sizeof(int)));
    for(int x= 0; x < CRAZY_TRAIN_LOOPS; x++){
      randomNumber = random(0,2);
      randomRelay = random(0,(sizeof(relaysForCrazyTrain)/sizeof(int)));
      int pin  = relaysForCrazyTrain[randomRelay];
      digitalWrite(pin, randomNumber);
      activity();
      delay(random(SLEEP_TIME_SHORT,SLEEP_TIME_MEDIUM));
    }
}
// the setup function runs once when you press reset or power the board
void setup() {
  //setup serial communications through the USB
  Serial.begin(115200);
  randomSeed(45);
  
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
  
  // Turn off all Lights
  digitalWrite(LED_BUILTIN, LOW);
  allOff(0);

  Serial.println("Setup done.");
   
}


// the loop function runs over and over again forever
void loop() {
  
  if(!firstLoopDone){
  
    for(int x=0; x<3;x++){
      Serial.print("Warmup loop = ");
      Serial.println(x);

      // Turn realys on
      Serial.print("Action = allOn("); Serial.print(SLEEP_TIME_WARMUP); Serial.println(")");
      allOn(SLEEP_TIME_WARMUP);

      // Turn relays off
      Serial.print("Action = allOff("); Serial.print(SLEEP_TIME_WARMUP); Serial.println(")");
      allOff(SLEEP_TIME_WARMUP);    
    }

    // Start with the first four plugs on
    Serial.println("Action = allOn(0)");
    allOn(0);
    
    firstLoopDone = true;
    
  }else{
    Serial.println("Doing main light show!");

    blink_relay_1();
    Serial.println(Action = delay(2500)");
    delay(2500);
    blink_relay_1();
    blink_crazy_train();
    allOff(0);
    delay(1000);
    blink_relay_1();
    allOn(378);

    
    
//     // **********
//

//     allOn(0);
//     delay(1000);

//     //turn all off and then turn on the three floor lamps
//     allOff(0);
//     delay(1000);

//     // Wake up the lights
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_LONG);
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_6,ON);
//     delay(SLEEP_TIME_LONG);
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_7,ON);
//     delay(SLEEP_TIME_LONG);
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_8,ON);
    
//     delay(SLEEP_TIME_LOOP);

//     // Blink relay 1 & 4
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);   
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);
//     delay(SLEEP_TIME_SHORT); 
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);        
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_8, ON); 

//     delay(SLEEP_TIME_LOOP);

// // Blink relay 1 & 4
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);   
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);
//     delay(SLEEP_TIME_SHORT); 
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);        
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_8, ON); 

//     delay(SLEEP_TIME_LOOP);

//     // Blink relay 1 & 4
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);   
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_LONG);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);
//     delay(SLEEP_TIME_SHORT); 
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);
//     digitalWrite(RELAY_8, ON);    
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, OFF);
//     digitalWrite(RELAY_8, OFF);        
//     delay(SLEEP_TIME_MEDIUM);
//     digitalWrite(RELAY_5, ON);    
//     delay(SLEEP_TIME_SHORT);
//     digitalWrite(RELAY_8, ON); 

//     delay(SLEEP_TIME_LOOP);
  }


                     
}
