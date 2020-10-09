/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

//  static int RELAY_1 = 2;
//  static int RELAY_2 = 3;
//  static int RELAY_3 = 4;
//  static int RELAY_4 = 5;
//  static int RELAY_5 = 6;
//  static int RELAY_6 = 7;

  static int RELAY_1 = 5;
  static int RELAY_2 = 6;
  static int RELAY_3 = 7;
  static int RELAY_4 = 2;
  static int RELAY_5 = 3;
  static int RELAY_6 = 4;

  static int RELAY_7 = 8;
  static int RELAY_8 = 9;
  static int RELAY_R = 10;
  static int RELAY_U = 11;
  static int RELAY_N = 12;
  int relaysForCrazyTrain[] = {RELAY_1,RELAY_2,RELAY_3,RELAY_4,RELAY_5,RELAY_6};
  
  static int DELAY = 1000;
  static int ON = LOW;
  static int OFF = HIGH;

  static int SLEEP_TIME_SHORT = 73;
  static int SLEEP_TIME_MEDIUM = 131;
  static int SLEEP_TIME_LONG = 237;
  static int SLEEP_TIME_WARMUP = 1000;
  static long SLEEP_TIME_LOOP = 30000;

  static int CRAZY_TRAIN_LOOPS = 300;
  static int CRAZY_TRAIN_LOOP_DELAY = 47;

  boolean firstLoopDone = false;
  int thirteen = LOW;
  long randomNumber;
  long randomRelay;

void allOn(){
 
  digitalWrite(RELAY_1, ON);
  digitalWrite(RELAY_2, ON);
  digitalWrite(RELAY_3, ON);
  digitalWrite(RELAY_4, ON);
  digitalWrite(RELAY_5, ON);
  digitalWrite(RELAY_6, ON);
  digitalWrite(RELAY_7, ON);
  digitalWrite(RELAY_8, ON);
  digitalWrite(RELAY_R, HIGH);
  digitalWrite(RELAY_U, HIGH);
  digitalWrite(RELAY_N, HIGH);
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
  digitalWrite(RELAY_R, LOW);
  digitalWrite(RELAY_U, LOW);
  digitalWrite(RELAY_N, LOW);
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
  pinMode(RELAY_R, OUTPUT);
  pinMode(RELAY_U, OUTPUT);
  pinMode(RELAY_N, OUTPUT);
  
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
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_1, ON);    
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_2, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_3, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_4, ON);   
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_5, ON);  
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_6, ON);  
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_7, ON);  
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_8, ON);  
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_R, HIGH);  
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_U, HIGH);    
      delay(SLEEP_TIME_WARMUP);
      digitalWrite(RELAY_N, HIGH);   
      delay(SLEEP_TIME_WARMUP);
      allOff();
    }
    delay(SLEEP_TIME_WARMUP);
    allOn();
    delay(SLEEP_TIME_WARMUP);
    allOff();
    delay(SLEEP_TIME_WARMUP);
    allOn();
    delay(SLEEP_TIME_WARMUP);
    allOff();
    delay(SLEEP_TIME_WARMUP);


    // Start with the floor lamps on
    digitalWrite(RELAY_1, ON);    
    digitalWrite(RELAY_2, ON);   
    digitalWrite(RELAY_3, ON);
    
    firstLoopDone = true;
    
  }else{
    
    if(thirteen == HIGH){
      digitalWrite(LED_BUILTIN, LOW);
      thirteen = LOW;
    }else{
      digitalWrite(LED_BUILTIN, HIGH);
      thirteen = HIGH;
    }

    // Blink Floor Lammp 1
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON); 
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON); 


    delay(2500);
    
    // Blink Floor Lamps 2 & 3

     digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_SHORT);
    
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_SHORT);
    
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_LONG);
     digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_2, ON); 
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, ON);
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_2, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_3, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_2, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_3, ON);
    digitalWrite(RELAY_1, ON); 


    delay(1333);
    allOff();
    delay(1741);
    
    // x-mas 1
    digitalWrite(RELAY_4, ON);
    delay(1700);
    
    // x-mas 2
    digitalWrite(RELAY_5, ON);
    delay(1700);

    // x-mas 3
    digitalWrite(RELAY_6, ON);
    delay(1700);

    // turn off x-mas lighs
    digitalWrite(RELAY_4, OFF);
    digitalWrite(RELAY_5, OFF);
    digitalWrite(RELAY_6, OFF);
    delay(1000);
    
    // R
    digitalWrite(RELAY_R, HIGH);
    delay(1984);
    digitalWrite(RELAY_R, LOW);
    delay(1000);
    
    // U
    digitalWrite(RELAY_U, HIGH);
    delay(1984);
    digitalWrite(RELAY_U, LOW);
    delay(1000);
    
    // N
    digitalWrite(RELAY_N, HIGH);
    delay(1984);
    digitalWrite(RELAY_N, LOW);
    delay(750);
    
    // R U N
    digitalWrite(RELAY_R, HIGH);
    digitalWrite(RELAY_U, HIGH);
    digitalWrite(RELAY_N, HIGH);
    delay(2000);

    //crazy train
    //(sizeof(CRAZY_TRAIN_LOOPS)/sizeof(int))
    Serial.print("Array size of relaysForCrazyTrain = ");
      Serial.println((sizeof(relaysForCrazyTrain)/sizeof(int)));
    for(int x= 0; x < CRAZY_TRAIN_LOOPS; x++){
      randomNumber = random(0,2);
      randomRelay = random(0,(sizeof(relaysForCrazyTrain)/sizeof(int)));
      int pin  = relaysForCrazyTrain[randomRelay];
      
//      Serial.print("State = ");
//      Serial.print(randomNumber);
//      Serial.print(", Relay = ");
//      Serial.print(randomRelay);
//      Serial.print(", PIN = ");
//      Serial.println(pin);
      digitalWrite(pin, randomNumber);
      delay(CRAZY_TRAIN_LOOP_DELAY);
    }

    allOn();
    delay(973);

    //turn all off and then turn on the three floor lamps
    allOff();
    delay(4313);

    // Wake up the lights
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_LONG);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_2,ON);
    delay(SLEEP_TIME_LONG);
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_3,ON);
    
    delay(SLEEP_TIME_LOOP/4);

    // keep some interest
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
  
    
    delay(SLEEP_TIME_LOOP/4);

    // keep some interest
    digitalWrite(RELAY_4, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_4, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_4, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_4, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_4, ON);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_4, OFF);
  

    delay(SLEEP_TIME_LOOP/4);
     // keep some interest
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_MEDIUM);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);
    digitalWrite(RELAY_1, OFF);    
    delay(SLEEP_TIME_LONG);
    digitalWrite(RELAY_1, ON);    
    delay(SLEEP_TIME_SHORT);

    delay(SLEEP_TIME_LOOP/4);
    
    
  }


                     
}
