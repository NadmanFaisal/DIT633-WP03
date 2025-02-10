/*

Improvements:-

Questions:-

#define DHTPIN A0 // define temperature pin as A0

int readingTemp; // temp reading from analogRead
float tempVolt; // set tempVolt to 0 (to measure voltage of temperature from the reading, 5V = 5000mv, 1V approx. 1024mv. readingTemp * (5000 / 1024.0))
float tempValue; // set tempValue based on formula provided in the specification for the exercise.

const long intervalPerHalfASecond = 500; // interval of half a second delay
long currentMillis = 0; // count current millis
long previousMillis = 0; // set previousMillis to 0 (this will be updated every loop to ensure it only does half a second)

void setup() {
  Serial.begin(9600); // start arduino communication to use serial.print
}

void loop() {
  readingTemp = analogRead(DHTPIN); // read temp value 
  tempVolt = readingTemp * (5000 / 1024.0); // calculate volt of the reading
  tempValue = (tempVolt - 500) / 10; // calculate temp value in celsius
  
  currentMillis = millis(); // count the time when program started from this point

  if (currentMillis - previousMillis >= intervalPerHalfASecond) { // if the time is more than half a second
    previousMillis = currentMillis; // save that time so that we can check in the if statement again, otherwise the program will keep entering if statement and not create opportunities where if its at 250ms it should not enter
    Serial.print("Temperature: "); // print temperature template
    Serial.println(tempValue); // print temp value
  }    
  
  
}

*/