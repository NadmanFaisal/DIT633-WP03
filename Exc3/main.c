/*

Improvements:-

Questions:-

#define DHTPIN A0

int readingTemp;
float tempVolt;
float tempValue;

const long intervalPerHalfASecond = 500;
long currentMillis = 0;
long previousMillis = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readingTemp = analogRead(DHTPIN);
  tempVolt = readingTemp * (5000 / 1024.0);
  tempValue = (tempVolt - 500) / 10;
  
  currentMillis = millis();

  if (currentMillis - previousMillis >= intervalPerHalfASecond) {
    previousMillis = currentMillis;
    Serial.print("Temperature: ");
    Serial.println(tempValue);
  }    
  
  
}

*/