/*
 Created from the base of http://www.arduino.cc/en/Tutorial/Blink
 
*/
  
  // RELAY_x to PIN mapping
  static int RELAY_1 = 5; // Chandelear
  static int RELAY_2 = 6; // Standing Lamp
  static int RELAY_3 = 7; // Spot LIght
  static int RELAY_4 = 2; // Road Light
  static int RELAY_5 = 3;
  static int RELAY_6 = 4;

  static int RELAY_7 = 8;
  static int RELAY_8 = 9;
  static int RELAY_R = 10;
  static int RELAY_U = 11;
  static int RELAY_N = 12;
  int relaysForCrazyTrain[] = {RELAY_5,RELAY_6,RELAY_7,RELAY_8};
  
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

void allOn(){
 
  //digitalWrite(RELAY_1, ON);
  //delay(SLEEP_TIME_SHORT);
  //digitalWrite(RELAY_2, ON);
  //delay(SLEEP_TIME_SHORT);
  //digitalWrite(RELAY_3, ON);
  //delay(SLEEP_TIME_SHORT);
  //digitalWrite(RELAY_4, ON);
  //delay(SLEEP_TIME_SHORT);
  digitalWrite(RELAY_5, ON);
  delay(SLEEP_TIME_SHORT);
  digitalWrite(RELAY_6, ON);
  delay(SLEEP_TIME_SHORT);
  digitalWrite(RELAY_7, ON);
  delay(SLEEP_TIME_SHORT);
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
  
  digitalWrite(LED_BUILTIN, LOW);
  allOff();

  Serial.println("Setup tests done.");
  Serial.print("ON = ");
  Serial.println(ON);
  Serial.print("OFF = ");
  Serial.println(OFF);
   
}

// the loop function runs over and over again forever
void loop() {
  
  if(!firstLoopDone){
  
    for(int x=0; x<3;x++){
      Serial.print("Warmup loop = ");
      Serial.println(x);
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_5, ON);    
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_5, OFF);
      digitalWrite(RELAY_6, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_6, OFF);
      digitalWrite(RELAY_7, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_7, OFF);
      digitalWrite(RELAY_8, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_8, OFF);
      
      allOff(); // just to make sure everything is turned off ;)

      delay(SLEEP_TIME_WARMUP);
      Serial.println("All ON");
      allOn();
      delay(SLEEP_TIME_WARMUP);
      Serial.println("All OFF");
      allOff();
      delay(SLEEP_TIME_WARMUP);
      Serial.println("All ON");
      allOn();
      delay(SLEEP_TIME_WARMUP);

      Serial.println("All OFF");
      allOff();
    
    }
    
    
    delay(SLEEP_TIME_WARMUP);


    // Start with the first four plugs on
    Serial.println("All Start lamps on");
    allOn();
    
    firstLoopDone = true;
    
  }else{
    Serial.println("Doing main light show!");
    
    if(thirteen == HIGH){
      digitalWrite(LED_BUILTIN, LOW);
      thirteen = LOW;
    }else{
      digitalWrite(LED_BUILTIN, HIGH);
      thirteen = HIGH;
    }

    // Blink Floor Lammp 1
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON); 
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON); 


    delay(2500);
    
    // **********
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
      delay(CRAZY_TRAIN_LOOP_DELAY);
    }

    allOn();
    delay(1000);

    //turn all off and then turn on the three floor lamps
    allOff();
    delay(1000);

    // Wake up the lights
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, OFF);    
    delay(SLEEP_TIME_SHORT);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_LONG);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_6,ON);
    delay(SLEEP_TIME_LONG);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_7,ON);
    delay(SLEEP_TIME_LONG);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_8,ON);
    
    delay(SLEEP_TIME_LOOP);

    // Blink relay 1 & 4
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);   
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);
    delay(SLEEP_TIME_SHORT); 
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);        
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_8, ON); 

    delay(SLEEP_TIME_LOOP);

// Blink relay 1 & 4
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);   
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);
    delay(SLEEP_TIME_SHORT); 
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);        
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_8, ON); 

    delay(SLEEP_TIME_LOOP);

    // Blink relay 1 & 4
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);   
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);
    delay(SLEEP_TIME_SHORT); 
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);
    digitalWrite(RELAY_8, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_8, OFF);        
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_5, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_8, ON); 

    delay(SLEEP_TIME_LOOP);
  }


                     
}
