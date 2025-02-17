#include <Keypad.h>

#define ROW1 11 // definig the row1 pin
#define ROW2 10 // definig the row2 pin
#define ROW3 9 // definig the row3 pin
#define ROW4 8 // definig the row4 pin
#define COLUMN1 7 // definig the column1 pin
#define COLUMN2 6 // definig the column2 pin
#define COLUMN3 5 // definig the column3 pin
#define COLUMN4 4 // definig the column4 pin

const int rows = 4; // stroing the row size
const int colums = 4; // storing the colmun size
int oneSec = 1000; // storing the delay value

char keys[rows][colums] = { // store the key values in the matrix
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPin[rows] = {ROW1, ROW2, ROW3, ROW4}; // initialize the array with row pin value
byte columnPin[colums] = {COLUMN1, COLUMN2, COLUMN3, COLUMN4}; // initialize the array with column pin value

Keypad keypad = Keypad(makeKeymap(keys), rowPin, columnPin, rows, colums); // creating the keypad

void setup() {
  Serial.begin(9600); // initialize the serial value

}

void loop() {
  
  char pressedKey = keypad.getKey(); // stornig the pressed key value
  
  if (pressedKey){ // checks if a key was pressed
    Serial.print(pressedKey); //print the pressed key
    delay(oneSec); //delay of one second
  }
}