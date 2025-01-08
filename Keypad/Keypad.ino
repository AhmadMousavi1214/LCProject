#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
const String password = "1459";

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

// here have to change when we want complete this project !
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String enteredDigits = "";

void setup() {
  Serial.begin(9600);
}


void printDigits(String enteredDigits) {
  Serial.println(enteredDigits);
}


void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '*') {
      if (enteredDigits.length() > 0) {
        enteredDigits.remove(enteredDigits.length() - 1);
        printDigits(enteredDigits);
      } else {
        // here we have to show the error message to the lcd  (after inpelimenting that) !
        Serial.println("the digits are not enough to delete them !");
      }
    } else if (key == '#') {
      if (enteredDigits.length() == 4) {
        printDigits(enteredDigits);
        // here we have to process thee the way that we want ot check is the entered digit is the same as password or not !
        // something like this imelimenation
        if (enteredDigits == password) {
          Serial.println("yot entered the correct password !");
        } else {
          Serial.println("you didnt entered the correct answer !");
        }
      } else {
        // here we have to say again in lcd you have not enough digit for analysing the password you entered !
        Serial.println("digits are not enough to check !");
      }
    } else {
      if (enteredDigits.length() >= 4) {
        // correct message in the lcd !
        Serial.println("you cant enter more than four digits !");
      } else {
        enteredDigits += key ;
        printDigits(enteredDigits);
      }
    }
  }
}