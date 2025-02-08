// C++ code
//

int redLED = 4;
int greenLED = 8;
int yellowLED = 7;

int tempPin = A0;
int lightPin = A1;
void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float tempReading = analogRead(tempPin);
  float voltage = tempReading * (5000 / 1024.0);
  float temperature = (voltage - 500) / 10;
  
  float lightReading = analogRead(lightPin);
  float intensity = map(lightReading, 6, 679, 0, 100);
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("\n");
  
  Serial.print("Intensity: ");
  Serial.print(intensity);
  Serial.print("\n");
  
// =========================================
  
  if(intensity < 1) {
    if(temperature < -12) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
    } else {
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
    }
  }

// =========================================
  
  else if(intensity >= 1 && intensity <= 20) {
    if(temperature < -12) {
      	digitalWrite(greenLED, LOW);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, HIGH);
    } else if(temperature > 0) {
      	digitalWrite(greenLED, LOW);
      	digitalWrite(redLED, HIGH);
      	digitalWrite(yellowLED, LOW);
    } else {
    	digitalWrite(greenLED, HIGH);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, LOW);
    }
  }
  
// =========================================
  else if(intensity >= 21 && intensity <= 60) {
    if(temperature < 0) {
    	digitalWrite(greenLED, LOW);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, HIGH);
    } else if(temperature > 20) {
    	digitalWrite(greenLED, LOW);
      	digitalWrite(redLED, HIGH);
      	digitalWrite(yellowLED, LOW);
    } else {
    	digitalWrite(greenLED, HIGH);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, LOW);
    }
  }
  
// =========================================
  
  else {
    if(temperature >= 21) {
    	digitalWrite(greenLED, HIGH);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, LOW);
    } else {
    	digitalWrite(greenLED, LOW);
      	digitalWrite(redLED, LOW);
      	digitalWrite(yellowLED, HIGH);
    }
  }
  

  
  delay(1000);
}