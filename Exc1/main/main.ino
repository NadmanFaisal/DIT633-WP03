int ledPin = 8;					  // Pin for the blinking LED
int ledPin2 = 7;				  // Pin for the switch LED
int buttonPin = 2;				// Pin for button
void setup() {
  	pinMode(buttonPin, INPUT);        // Initializes button pin as INPUT
  	pinMode(ledPin2, OUTPUT);	        // Initizlises OUTPUT for shwoing light
    pinMode(ledPin,OUTPUT);		        // Initizlises OUTPUT for shwoing light
}
void loop()	{  
  if(digitalRead(buttonPin) == HIGH) {			// If button is pressed
  	digitalWrite(ledPin2, HIGH);				    // light is off
  } else {										              // else if button not pressed
  	digitalWrite(ledPin2, LOW);					    // light is on
  }
    digitalWrite(ledPin,HIGH);				// turns light on
    delay(1000);							        // waits one second
    digitalWrite(ledPin,LOW);				  // turns light off
    delay(1000);							        // waits one second
}