int ledPin = 8;
int ledPin2 = 7;
int buttonPin = 2;
void setup() {
  	pinMode(buttonPin, INPUT);
  	pinMode(ledPin2, OUTPUT);
    pinMode(ledPin,OUTPUT);
}
void loop()	{  
  if(digitalRead(buttonPin) == LOW) {
  	digitalWrite(ledPin2, LOW);
  } else {
  	digitalWrite(ledPin2, HIGH);
  }
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
    delay(1000);
}