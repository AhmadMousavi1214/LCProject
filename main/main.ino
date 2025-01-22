#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<BCDsegment.h>

// lcd cofigs
const int LCD_RS = 12, LCD_EN = 11, LCD_D4 = 10, LCD_D5 = 9, LCD_D6 = 8, LCD_D7 = 7;
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// keypad configs
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};
byte rowPins[ROWS] = {6, 5, 4, 3};
byte colPins[COLS] = {2, A0, A1};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//quad BCDsegment configs
const int BCDsegment_initial = 13;
BCDsegment quadSegment(BCDsegment_initial);

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
            quadSegment.DisplayPass(enteredPassword)
        } else {
            displayMessage("No digits to", "delete!");
        }
    } else if (key == '#') {
        // if we were in 0 state :
        if (state == 0) {
            if (enteredPassword == correctPassword) {
                displayMessage("Password Correct!", "Change it now.");
                state = 1;
            } else {
                displayMessage("Password Incorrect!", "Try again.");
            }
        } else if (state == 1) {
            // if we were in 1 atate :
            newPassword = enteredPassword;
            displayMessage("Confirm New", "Password:");
            state = 2;
        } else if (state == 2) {
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
    } else {
        // Append the entered digit
        if (enteredPassword.length() < 4) {
            enteredPassword += key;
            displayMessage("Enter Password:");
            quadSegment.DisplayPass(enteredPassword)
        } else {
            displayMessage("Limit Reached!", "Max 4 digits.");
        }
    }
}

void setup() {
    lcd.begin(16, 2);
    displayMessage("Enter Password:");
}

void loop() {
    char key = keypad.getKey();

    if (key) {
        handlePasswordInput(key);
    }
}
