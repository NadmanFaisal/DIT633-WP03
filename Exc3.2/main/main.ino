int row1 = 11;
int row2 = 10;
int row3 = 9;
int row4 = 8;

int col1 = 7;
int col2 = 6;
int col3 = 5;
int col4 = 4;

char key;

void setup ()
{
  Serial.begin(9600);
  
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);
  pinMode(col3, INPUT_PULLUP);
  pinMode(col4, INPUT_PULLUP);
  
}

void loop() 
{
  key = getKey();
  
  if(key) {
    Serial.print(key);
    Serial.print("\n");
  
  }
  
  delay(1000);

}

char getKey() 
{
  char character;
// =============================
  digitalWrite(row1, LOW);
  if(digitalRead(col1) == LOW) {
    character = '1';
  	
  }
  if(digitalRead(col2) == LOW) {
    character = '2';
  	
  }
  if(digitalRead(col3) == LOW) {
    character = '3';
  }
  if(digitalRead(col4) == LOW) {
    character = 'A';
  }
  digitalWrite(row1, HIGH);
  
// =============================
  
  digitalWrite(row2, LOW);
  if(digitalRead(col1) == LOW) {
    character = '4';
  	
  }
  if(digitalRead(col2) == LOW) {
    character = '5';
  	
  }
  if(digitalRead(col3) == LOW) {
    character = '6';
  }
  if(digitalRead(col4) == LOW) {
    character = 'B';
  }
  digitalWrite(row2, HIGH);
  
// =============================
  
  digitalWrite(row3, LOW);
  if(digitalRead(col1) == LOW) {
    character = '7';
  	
  }
  if(digitalRead(col2) == LOW) {
    character = '8';
  	
  }
  if(digitalRead(col3) == LOW) {
    key = '9';
  }
  if(digitalRead(col4) == LOW) {
    character = 'C';
  }
  digitalWrite(row3, HIGH);
  
// =============================
  
  digitalWrite(row4, LOW);
  if(digitalRead(col1) == LOW) {
    character = 'F';
  	
  }
  if(digitalRead(col2) == LOW) {
    character = '0';
  	
  }
  if(digitalRead(col3) == LOW) {
    character = 'E';
  }
  if(digitalRead(col4) == LOW) {
    character = 'D';
  }
  digitalWrite(row4, HIGH);

// =============================
  
  return character;
  
}