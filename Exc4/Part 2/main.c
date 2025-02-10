/*
// library for keypad
#include <Keypad.h>

// define list of Port Bs for the rows
#define LISTOFROWS {11, 10, 9, 8}
// define list of Port Ds for the columns
#define LISTOFCOLUMNS {7, 6, 5, 4}

byte listOfRowPins[] = LISTOFROWS; // list of rows
byte listOfColumnPins[] = LISTOFCOLUMNS; //  list of columns

// list of buttons with their respective characters
char keyPadButtons[sizeof(listOfRowPins)][sizeof(listOfColumnPins)] = {{'1','2','3','A'},
                            		  							   	   {'4','5','6','B'},
                          		      							   	   {'7','8','9','C'},
                          		      							   	   {'E','0','F','D'}};

char keypadUserInput; // store user input from keypad

// initalizes instance of Keypad class
Keypad keypad1 = Keypad(makeKeymap(keyPadButtons), listOfRowPins, listOfColumnPins, (sizeof(listOfRowPins) / sizeof(listOfRowPins[0])), (sizeof(listOfColumnPins) / sizeof(listOfColumnPins[0])) );

void setup() {
  
  Serial.begin(9600); // start arduino communication to use serial.print

}

// function that reads if user input something on the keypad
char keypadChecker(){  
  char userInput = keypad1.getKey(); // read user input from keypad and store in variable
  
  return userInput; // return input
}

void loop() {
  
  keypadUserInput = keypadChecker(); // enter function to check what key is pressed and save in a variable.
  
  if(keypadUserInput != NO_KEY){ // if the input isnt empty, meaning the user clicked something
    Serial.print("Keypad input: "); // print keypad template
    Serial.println(keypadUserInput); // print key value
  }
  
  delay(1000); // delay 1 second
  
}

*/