// Predefined macros for rows and columns pins
#define row1 11
#define row2 10
#define row3 9
#define row4 8

#define col1 7
#define col2 6
#define col3 5
#define col4 4

char key;                   // Variable to hold the key char value

void setup ()
{
  Serial.begin(9600);       // Initializes the serial for printing values
  
  pinMode(row1, OUTPUT);    // row1 pin initialized as OTUPUT to control the row
  pinMode(row2, OUTPUT);    // row2 pin initialized as OTUPUT to control the row
  pinMode(row3, OUTPUT);    // row3 pin initialized as OTUPUT to control the row
  pinMode(row4, OUTPUT);    // row4 pin initialized as OTUPUT to control the row
  
  pinMode(col1, INPUT);     // col1 initialized as input to get reading
  pinMode(col2, INPUT);     // col2 initialized as input to get reading
  pinMode(col3, INPUT);     // col3 initialized as input to get reading
  pinMode(col4, INPUT);     // col4 initialized as input to get reading
  
  
}

void loop() 
{
  key = getKey();           // Stores the returned character in key variable
  
  if(key != '\0') {         // If characters are returned, 
    Serial.print(key);      // Prints the character in the serial
    Serial.print("\n");     // New line to print other character when returned
  
  }
  
  delay(1000);              // Delay for one second

}

/*
This method is responsible for returning the value of the key pressed.
If a specific column and specific row are LOW at the same time, it 
indicates that THAT specific key has been pressed.
*/
char getKey() 
{
  char character = '\0';              // Initially, no character is returned
// =============================
  digitalWrite(row1, LOW);            // Row1 set to low to to detect if any column in pressed
  if(digitalRead(col1) == LOW) {      // If col1 is pressed, 
    character = '1';                  // sets the variable to 1
  	
  }
  if(digitalRead(col2) == LOW) {      // If col 2 is pressed, 
    character = '2';                  // Sets the variable to 2
  	
  }
  if(digitalRead(col3) == LOW) {      // If col3 is pressed. 
    character = '3';                  // Sets the variable to 3
  }
  if(digitalRead(col4) == LOW) {      // If col4 is pressed, 
    character = 'A';                  // Sets the variable to A
  }
  digitalWrite(row1, HIGH);           // Sets the row1 back to high to detect keypress in other rows
  
// =============================
  
  digitalWrite(row2, LOW);            // // Row2 set to low to to detect if any column in pressed
  if(digitalRead(col1) == LOW) {      // If col1 is pressed, 
    character = '4';                  // sets the variable to 4
  	
  }
  if(digitalRead(col2) == LOW) {      // If col 2 is pressed, 
    character = '5';                  // Sets the variable to 5
  	
  }
  if(digitalRead(col3) == LOW) {      // If col3 is pressed. 
    character = '6';                  // Sets the variable to 6
  }
  if(digitalRead(col4) == LOW) {      // If col4 is pressed. 
    character = 'B';                  // Sets the variable to B
  }
  digitalWrite(row2, HIGH);           // Sets the row2 back to high to detect keypress in other rows
  
// =============================
  
  digitalWrite(row3, LOW);            // // Row3 set to low to to detect if any column in pressed
  if(digitalRead(col1) == LOW) {      // If col1 is pressed, 
    character = '7';                  // sets the variable to 7
  	
  }
  if(digitalRead(col2) == LOW) {      // If col2 is pressed, 
    character = '8';                  // sets the variable to 8
  	
  }
  if(digitalRead(col3) == LOW) {      // If col3 is pressed, 
    character = '9';                  // sets the variable to 9
  }
  if(digitalRead(col4) == LOW) {      // If col4 is pressed, 
    character = 'C';                  // sets the variable to C
  }
  digitalWrite(row3, HIGH);           // Sets the row3 back to high to detect keypress in other rows
  
// =============================
  
  digitalWrite(row4, LOW);            // // Row3 set to low to to detect if any column in pressed
  if(digitalRead(col1) == LOW) {      // If col1 is pressed, 
    character = 'F';                  // sets the variable to F
  	
  }
  if(digitalRead(col2) == LOW) {      // If col2 is pressed, 
    character = '0';                  // sets the variable to 0
  	
  }
  if(digitalRead(col3) == LOW) {      // If col3 is pressed, 
    character = 'E';                  // sets the variable to R
  }
  if(digitalRead(col4) == LOW) {      // If col4 is pressed, 
    character = 'D';                  // sets the variable to D
  }
  digitalWrite(row4, HIGH);           // Sets the row3 back to high to detect keypress in other rows

// =============================
  
  return character;                   // Returns the character
  
}