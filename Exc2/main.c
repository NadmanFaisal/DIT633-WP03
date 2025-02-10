/*

Improvements:-

change byte as it doesn't fit C programming

Questions:-



#define DHTPIN A0
#define LIGHTPIN A1

int redLEDPin = 9;
int greenLEDPin = 11;
int yellowLEDPin = 13;

float readingLight = 0.0;
float lightValue = 0.0;

const long intervalPerSecond = 1000; 
long previousMillis = 0;

byte redLEDState = LOW;
byte greenLEDState = LOW;
byte yellowLEDState = LOW;


void setup()
{
  Serial.begin(9600);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
}

void loop()
{
  
  int readingTemp = analogRead(DHTPIN);
  float tempVolt = readingTemp * (5000 / 1024.0);
  float tempValue = (tempVolt - 500) / 10;
  
  readingLight = analogRead(LIGHTPIN);
  lightValue = map(readingLight, 0, 471, 0, 100);
  
  if(lightValue >= 61 && lightValue <= 100){
    if(tempValue >= 21){
      greenLEDState = HIGH;
    } else {
      yellowLEDState = HIGH;
    }
  } else if (lightValue >= 21 && lightValue < 61){
    if(tempValue > 20){
      redLEDState = HIGH;
    } else if (tempValue <= 20 && tempValue >= 0){
      greenLEDState = HIGH;
    } else {
      yellowLEDState = HIGH;
    }
  } else if(lightValue >= 1 && lightValue < 20){
    if(tempValue > 0){
      redLEDState = HIGH;
    } else if(tempValue <= 0 && tempValue >= -12){
      greenLEDState = HIGH;
    } else {
      yellowLEDState = HIGH;
    }
  } else {
    if(tempValue > -12){
      redLEDState = HIGH;
    } else {
      greenLEDState = HIGH;
    }
  }
  
  digitalWrite(redLEDPin, redLEDState);
  digitalWrite(greenLEDPin, greenLEDState);
  digitalWrite(yellowLEDPin, yellowLEDState);

  long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalPerSecond) {
    previousMillis = currentMillis;
    Serial.print("Temperature: ");
    Serial.println(tempValue);
    Serial.print("Light Intensity: ");
    Serial.println(readingLight);
  }    
  
}
*/