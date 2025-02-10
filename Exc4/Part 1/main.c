/*
// define list of Port Bs for the rows
#define LISTOFROWS {11, 10, 9, 8}
// define list of Port Ds for the columns
#define LISTOFCOLUMNS {7, 6, 5, 4}
// define interval of a second delay per specification
#define INTERVALPERSECOND 1000

long currentMillis = 0; // count current millis
long previousMillis = 0; // set previousMillis to 0 (this will be updated every loop to ensure it only does a second)

const int listOfRows[] = LISTOFROWS; // list of rows
const int listOfColumns[] = LISTOFCOLUMNS; //  list of columns

char keypadUserInput; // user input from keypad


void setup() {
  
  Serial.begin(9600); // start arduino communication to use serial.print
  
  for(int row = 0; row < (sizeof(listOfRows) / sizeof(listOfRows[0])); row++){ // for each row
    pinMode(listOfRows[row], OUTPUT); // make the pin to output
    digitalWrite(listOfRows[row], HIGH); // make it high all time
  }
  
  for(int column = 0; column < (sizeof(listOfColumns) / sizeof(listOfColumns[0])); column++){ // for each column
    pinMode(listOfColumns[column], INPUT); // set the columns to input
  }


}

// function that reads if user input something on the keypad
char keypadChecker(){
  char userInput = '\0'; // user input character
  
  // list of buttons with their respective characters
  char keyPadButtons[sizeof(listOfRows)][sizeof(listOfColumns)] = {{'1','2','3','A'},
                            		  							   {'4','5','6','B'},
                          		      							   {'7','8','9','C'},
                          		      							   {'E','0','F','D'}};
  
  // for each row
  for(int row = 0; row < (sizeof(listOfRows) / sizeof(listOfRows[0])); row++){
    
    digitalWrite(listOfRows[row], LOW); // make the row LOW
    
    for(int column = 0; column < (sizeof(listOfColumns) / sizeof(listOfColumns[0])); column++){ // for each column
      if(digitalRead(listOfColumns[column]) == LOW){ // if that column pressed was low, so if [0][1] which is 2 is LOW then
        userInput = keyPadButtons[row][column]; // save the input
      }
    }
    
    digitalWrite(listOfRows[row], HIGH); // make the row back to HIGH

  }
  
  return userInput; // return input
}

void loop() {

  keypadUserInput = keypadChecker(); // enter function to check what key is pressed and save in a variable.
  
  currentMillis = millis(); // count the time when program started from this point

  if (currentMillis - previousMillis >= INTERVALPERSECOND) { // if the time is more than a second
    previousMillis = currentMillis; // save that time so that we can check in the if statement again, otherwise the program will keep entering if statement and not create opportunities where if its at 250ms it should not enter
  	if(keypadUserInput != '\0'){ // if the input isnt empty, meaning the user clicked something
  	  Serial.print("Keypad input: "); // print keypad template
  	  Serial.println(keypadUserInput); // print key value
  	}
  }    
  
}
*/