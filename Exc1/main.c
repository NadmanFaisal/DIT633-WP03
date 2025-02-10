/*

Improvements:-

For more closer to C, we could do if digitalRead(buttonPin) == HIGH or 1 and remove variable declaration

Questions:-

int buttonPin = 7;
int led11Pin = 11;
int led8Pin = 8;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(led11Pin, OUTPUT);
  pinMode(led8Pin, OUTPUT);
}

void loop()
{

  byte buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    digitalWrite(led8Pin, LOW);
  } else {
    digitalWrite(led8Pin, HIGH);
  }
  
  digitalWrite(led11Pin, HIGH);
  delay(1000);
  digitalWrite(led11Pin, LOW);
  delay(1000);
}
*/