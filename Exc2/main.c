/*

Improvements:-

change byte as it doesn't fit C programming

Questions:-


// define DHTPIN as A0
#define DHTPIN A0
// define LIGHTPIN as A1
#define LIGHTPIN A1

// define REDLEDPIN as 9
#define REDLEDPIN 9
// define greenLEDPin as 9
#define GREENLEDPIN 11
// define yellowLEDPin as 13
#define YELLOWLEDPIN 13

float readingLight = 0.0; // set readingLight to 0 (to read analogRead value)
float lightValue = 0.0; // set lightValue to 0 (to map lightValue based on reading and specifications)

int readingTemp = 0; // set readingTemp to 0 (to read analogRead value)
float tempVolt = 0.0; // set tempVolt to 0 (to measure voltage of temperature from the reading, 5V = 5000mv, 1V approx. 1024mv. readingTemp * (5000 / 1024.0))
float tempValue = 0.0; // set tempValue based on formula provided in the specification for another exercise.

const long intervalPerSecond = 1000;  // set intervalPerSecond to 1 second (to be used alongside millis to delay for 1000ms without stopping the flow of resources in the program)
long previousMillis = 0; // set previousMillis to 0 (this will be updated every loop to ensure it only does a second)

byte redLEDState = LOW; // set redLEDState to 0 or LOW
byte greenLEDState = LOW; // set greenLEDState to 0 or LOW
byte yellowLEDState = LOW; // set yellowLEDState to 0 or LOW


void setup()
{
  Serial.begin(9600); // begin arduino communication, to allow for use of Serial.print 
  pinMode(REDLEDPIN, OUTPUT); // set red LED pin to output
  pinMode(GREENLEDPIN, OUTPUT); // set green LED pin to output
  pinMode(YELLOWLEDPIN, OUTPUT); // set yellow LED pin to output
}

void loop()
{
  
  readingTemp = analogRead(DHTPIN); // read temp value from analogRead
  tempVolt = readingTemp * (5000 / 1024.0); // switch temp reading to volt
  tempValue = (tempVolt - 500) / 10; // switch volt of temp to temp value in Celsius
  
  readingLight = analogRead(LIGHTPIN); // read light value from analogRead
  lightValue = map(readingLight, 0, 471, 0, 100); // map the reading based on specification (from 0% to 100%)
  
  // this is like a dependency table where the temperature is
  // dependent on the value of the light sensor.
  // To visualize the changes in both light and temperature,
  // we use LED's to signify if its out of bounds where,
  // RED is too high of that bound, YELLOW is too low of that bound,
  // and the GREEN is in that bound. Here is the chart from the assignment specification
  // to help you understand further:-

  //   Temperature            Light intensity
  //    < -12 °C                    0 %                
  //  -12 °C - 0 °C              1% - 20%
  //   0 °C - 20 °C              21% - 60%
  //     >= 21 °C                61% - 100%


  if(lightValue >= 61 && lightValue <= 100){ // if light value is wtihin 61% to 100&
    if(tempValue >= 21){ if temp value is less than 21 degrees
      greenLEDState = HIGH; // set green LED  state to on
    } else { // if its 21 or higher
      yellowLEDState = HIGH; // set yellow LED state to on
    }
  } else if (lightValue >= 21 && lightValue < 61){ // if light value is within 21% to 60%
    if(tempValue > 20){ // if temp value is greater than 20
      redLEDState = HIGH; // set red LED state to on
    } else if (tempValue <= 20 && tempValue >= 0){ // if its in between 20 and 0
      greenLEDState = HIGH; // set green LED  state to on
    } else { // if less than 0
      yellowLEDState = HIGH; // set yellow LED state to on
    }
  } else if(lightValue >= 1 && lightValue < 20){ // if light value is within 1% to 20%
    if(tempValue > 0){ // if temp value is greater than 0
      redLEDState = HIGH; // set red LED state to on
    } else if(tempValue <= 0 && tempValue >= -12){ // if temp value is within 0 and -12
      greenLEDState = HIGH; // set green LED  state to on
    } else { // if its less than -12
      yellowLEDState = HIGH; // set yellow LED state to on
    }
  } else { // if light value is 0%
    if(tempValue > -12){ // if temp value is more than -12
      redLEDState = HIGH; // set red LED state to on
    } else { // if temp value is less than -12
      greenLEDState = HIGH; // set green LED  state to on
    }
  }
  
  digitalWrite(REDLEDPIN, redLEDState); // set the red LED bsaed on its state we measured above
  digitalWrite(GREENLEDPIN, greenLEDState); // set the green LED bsaed on its state we measured above
  digitalWrite(YELLOWLEDPIN, yellowLEDState);  // set the yellow LED bsaed on its state we measured above


  // millis is a alternative to using delay,
  // since using delay halts the resources, effectively stopping
  // any other resources under this if statement to trigger
  // it is of better practice to use millis, since counting when
  // the program started, you can effectively have certain actions be done under a 
  // specific interval of time, where here I set my interval to every second.

  long currentMillis = millis(); // count the time when program started from this point

  if (currentMillis - previousMillis >= intervalPerSecond) { // if the time is more than a second
    previousMillis = currentMillis; // save that time so that we can check in the if statement again, otherwise the program will keep entering if statement and not create opportunities where if its at 500ms it should not enter
    Serial.print("Temperature: "); // print temperature template
    Serial.println(tempValue); // print temp value
    Serial.print("Light Intensity: "); // print light intensity template
    Serial.println(readingLight); // print light intensity value
  }    
  
}
*/