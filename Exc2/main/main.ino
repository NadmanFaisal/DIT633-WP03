int redLED = 4;           // pin for red LED
int greenLED = 8;         // pin for green LED
int yellowLED = 7;        // pin for yellow LED

int tempPin = A0;         // analog pin for temperature sensor
int lightPin = A1;        // analog pin for photoresistor (light sensor)

int period = 1;           // period delay in seconds

void setup()
{
  pinMode(redLED, OUTPUT);        // Initializes as output to display light
  pinMode(greenLED, OUTPUT);      // Initializes as output to display light
  pinMode(yellowLED, OUTPUT);     // Initializes as output to display light
  Serial.begin(9600);             // Initializes the serial to print values
}

void loop()
{
  float tempReading = analogRead(tempPin);                // stores the readings from analog tempPin
  float voltage = tempReading * (5000 / 1024.0);          // converts the analog reading to voltage
  float temperature = (voltage - 500) / 10;               // converts the voltage to temperature
  
  float lightReading = analogRead(lightPin);              // Reads from analog pin of lightPin
  float intensity = map(lightReading, 6, 679, 0, 100);    // Maps the min and max of light reading to percentage, indicating intensity
  
  // Prints the temperature value
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("\n");
  
  // Prints the intensity value
  Serial.print("Intensity: ");
  Serial.print(intensity);
  Serial.print("\n");
  
// =========================================
  
  /* Lights LEDs depending on the dependency between intensity and temperature */
  
  if(intensity < 1) {                                 // If intensity is less than 0
    if(temperature < -12) {                           // If temperature is less than -12 degrees
      digitalWrite(greenLED, HIGH);                   // green LED turned on
      digitalWrite(redLED, LOW);                      // red LED turned off
      digitalWrite(yellowLED, LOW);                   // yellow LED turned off
    } else {                                          // else if temperature temperature is greater than or equal to -12 degrees
      digitalWrite(greenLED, LOW);                    // turns off green LED
      digitalWrite(redLED, HIGH);                     // turns on red LED
      digitalWrite(yellowLED, LOW);                   // turns off yellow LED
    }
  }

// =========================================
  
  else if(intensity >= 1 && intensity <= 20) {      // If intensity is within 1 to 20 range
    if(temperature < -12) {                         // and if temp is less than -12
      	digitalWrite(greenLED, LOW);                // turns off green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, HIGH);              // turns on yellow LED
    } else if(temperature > 0) {                    // if temperature is greater than 0
      	digitalWrite(greenLED, LOW);                // turns off green LED
      	digitalWrite(redLED, HIGH);                 // turns on red LED
      	digitalWrite(yellowLED, LOW);               // turns off yellow LED
    } else {                                        // else,
    	digitalWrite(greenLED, HIGH);                 // turns on green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, LOW);               // turns off yellow LED
    }
  }
  
// =========================================
  else if(intensity >= 21 && intensity <= 60) {     // If intensity is within 21 to 60 range
    if(temperature < 0) {                           // and if temp is less than 0
    	  digitalWrite(greenLED, LOW);                // turns off green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, HIGH);              // turns on yellow LED
    } else if(temperature > 20) {                   // if temperature is greater than 20
    	  digitalWrite(greenLED, LOW);                // turns off green LED
      	digitalWrite(redLED, HIGH);                 // turns on red LED
      	digitalWrite(yellowLED, LOW);               // turns off yellow LED
    } else {
    	  digitalWrite(greenLED, HIGH);               // turns on green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, LOW);               // turns off yellow LED
    }
  }
  
// =========================================
  
  else {                                            // else if intensity is greater than 60
    if(temperature >= 21) {                         // and if temperature is greater than 20
    	digitalWrite(greenLED, HIGH);                 // turns on green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, LOW);               // turns off yellow LED
    } else {                                        // if temp is less than 21
    	digitalWrite(greenLED, LOW);                  // turns off green LED
      	digitalWrite(redLED, LOW);                  // turns off red LED
      	digitalWrite(yellowLED, HIGH);              // turns on yellow LED
    }
  }
  

  
  delay(period * 1000);               // Delays the program by the seconds mentioned in period variable
}