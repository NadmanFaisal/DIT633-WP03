#define TEMP_PIN A0 // defining temperature pin

void setup()
{
  Serial.begin(9600); // initialize serial
  pinMode(TEMP_PIN, INPUT); // initialize temp pin
}

void loop()
{
  float temp = analogRead(TEMP_PIN); // store the analog value in temp
  
  float volt = (temp) * 4.9; // convert the analog value to volt
  temp = (volt - 500)/10; // convert the volt to degree (C)
  
  
  Serial.println("Voltage: "); // print line for voltage
  Serial.println(volt); // print volt value
  Serial.println("Temp C: "); // print line for temp c
  Serial.println(temp); // print the temp value
  delay(500); // delay of 0.5 seconds
  
}