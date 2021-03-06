// Built based on https://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
/*--------------------------------------------------------------
  Program:      NonoVoltMeter

  Description:  Reads value on analog input A2 and calculates
                the voltage assuming that a voltage divider
                network on the pin divides by 11.
  
  Hardware:     Arduino Nano (Elegoo ATmega328P and chip CH340) with voltage divider on A2.
                
  Software:     Developed using Arduino 1.8.11 software

  Date:         2020-05-18
 
  Author:       Modified by David T. Wilson. Original author: W.A. Smith, http://startingelectronics.org
--------------------------------------------------------------*/

// number of analog samples to take per reading
#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
    Serial.print(voltage * 11.132);
    Serial.println (" V");
    sample_count = 0;
    sum = 0;

  delay(1000);
}
