#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BCDsegment.h"

// lcd cofigs
const int LCD_RS = 12, LCD_EN = 11, LCD_D4 = 10, LCD_D5 = 9, LCD_D6 = 8, LCD_D7 = 7;
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);


// this pin is for changing password
const int changePass = 13;
const int exitPin = 14;

// keypad configs
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { 3, 4, 5, 6 };
byte colPins[COLS] = { 2, 1, 0 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//quad BCDsegment configs
const int BCDsegment_initial = 22;
BCDsegment quadSegment = BCDsegment(BCDsegment_initial);

// password configs
String correctPassword = "0000";
String enteredPassword = "";
String newPassword = "";
int state = 0;
//explanation of states :
// 0: enter password, 1: password correct, 2: set new password

// func to display in lcd
void displayMessage(String line1, String line2 = "") {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void handlePasswordInput(char key) {
  if (key == '*') {
    // here we check if the number of digits are 0 it cant delete !!!
    if (!enteredPassword.length() == 0) {
      enteredPassword.remove(enteredPassword.length() - 1);
      displayMessage("Enter Password:");
      quadSegment.DisplayPass(enteredPassword);
    } else {
      displayMessage("No digits to", "delete!");
    }
  } else if (key == '#') {
    // if we were in 0 state :
    if (enteredPassword.length() == 4) {
      if (state == 0) {
        if (enteredPassword == correctPassword) {
          displayMessage("Password Correct!", "Change it now.");
          state = 1;
        } else {
          displayMessage("PasswordIncorrect !", "Try again.");
        }

      }
      // else if (state == 1) {

      // }
      else if (state == 2) {
        // if we were in 1 atate :
        newPassword = enteredPassword;
        displayMessage("Confirm New", "Password:");
        state = 3;
      } else if (state == 3) {
        // if we werr in 2 state :
        if (enteredPassword == newPassword) {
          correctPassword = newPassword;
          displayMessage("Password Changed", "Successfully!");
          // after changing the password we will go to the state 0 or we can go to the state 1 !
          state = 0;
        } else {
          displayMessage("Mismatch!", "Try again.");
        }
      }
      enteredPassword = "";
      quadSegment.DisplayPass(enteredPassword);
    }else{
      displayMessage("The pass is","less than 4bit");
    }
  } else {
    // Append the entered digit
    if (enteredPassword.length() < 4) {
      enteredPassword += key;
      displayMessage("Enter Password:");
      quadSegment.DisplayPass(enteredPassword);
    } else {
      displayMessage("Limit Reached!", "Max 4 digits.");
    }
  }
}

void setup() {
  pinMode(changePass, INPUT_PULLUP);
  pinMode(exitPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  quadSegment.DisplayPass(enteredPassword);
  displayMessage("Enter password:");
}

void loop() {
  char key = keypad.getKey();
  if (digitalRead(changePass) == LOW && state == 1) {
    displayMessage("Enter new pass:");
    state = 2;
  }
  if (digitalRead(exitPin) == LOW && state == 1) {
    state = 0;
    enteredPassword = "";
    displayMessage("Enter password:");
    quadSegment.DisplayPass(enteredPassword);
  }
  if (key) {
    handlePasswordInput(key);
  }
}
