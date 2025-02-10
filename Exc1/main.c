/*

Improvements:-

For more closer to C, we could do if digitalRead(buttonPin) == HIGH or 1 and remove variable declaration

Questions:-

int buttonPin = 7; // pin for the button
int led11Pin = 11; // pin for the constant blinking led 
int led8Pin = 8; // pin for the button-pressed led

void setup()
{
  pinMode(buttonPin, INPUT); // set pin mode for button to input
  pinMode(led11Pin, OUTPUT); // set pin mode for constant blinking led to output
  pinMode(led8Pin, OUTPUT);  // set pin mode for button-pressed led to output
}

void loop()
{

  byte buttonState = digitalRead(buttonPin); // read from button pin and add it to a variable called button state
  if(buttonState == HIGH){ // if the button is on
    digitalWrite(led8Pin, LOW); // set the button-pressed led to off
  } else { // else
    digitalWrite(led8Pin, HIGH); // set the button-pressed led to on
  }
  
  digitalWrite(led11Pin, HIGH); // set the constant blinking led to on
  delay(1000); // delay for 1 second
  digitalWrite(led11Pin, LOW); // set the constant blinking led to off
  delay(1000); // delay for 1 second
}
*/