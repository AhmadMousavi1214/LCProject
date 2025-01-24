
# Keypad cofigurations
for entering numbers and two imprtant keys # , * we used a 3 in 4 keypad which satisfy all of the requiers .

## Importing and making object
- at the first we download the keypad library 3.1.0
- now we need to assign some base to the keypad it need 4 bases for rows and 3 bases for columns
- by using the constructor of the keypad now we can make an instance of this

```cpp:
#include<Keypad.h>

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
```

## Usage and functions

- when the user choose a key we use a builtin function named getKey()
- by this function we can understand user choosed which of the keys so we can analyz the action and have a appropriate feedback
- we use getKey() in the loop and put the return of this function to a char and pass it as an input to the handlePasswordInput()

## Impelimnting handlePasswordInput() function

- this function cheks the charactor user entered with considering the state we defined for any sitiuation we can be in
* it have three main condition :
  * if key is *
  * if key is #
  * and the other keys (numbers)

* in the # mode it have 4 states :
  * 0: enter password
  * 1: password correct , we wait here until the user make a choise (change pass or exit)
  * 2: it is for the time user deside to change the pass and enter the new pass for the first time
  * 3: this state is for confirming the new pass . after this the corrct pass will be change to new pass ! and we go to the 0 state

## Using

```cpp:
void loop() {
    char key = keypad.getKey();

    if (key) {
        handlePasswordInput(key);
    }
}
```