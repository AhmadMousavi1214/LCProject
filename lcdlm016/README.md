# lcd lm016 
## intrduction
In this project, we used 16*2 LCD, which means that you cannot display more than 16 characters in each line. 
On the other hand, since we did not need very large data, we only used 4-bit LCD.
we used lcdlm016 as displayer unit for show massages such as $success$ and $fail$ .
# initialization
## set arduino pins
to using this feature , first you most have set 6 of your $arduino$ pins that used for lcd by this code. 
before it you most include liquidcrystal library in yoyur code . 
like this sample . ( It doesn't matter which pins you use to connect.)

```cpp:
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
```

Then you have to give the command to turn on the $LCD$ in the setup.

```cpp:
void setup() {
  lcd.begin(16, 2);
}
```

then you can use this function namayesh to show your message in $lcd lm016$

```cpp:
void namayesh(String matn1 , String matn2="")
{
    lcd.clear();
    lcd.setCursor(0,0);
    if(matn1!="")
        lcd.print(matn1);
    lcd.setCursor(0,1);
    if(matn2!="")
        lcd.print(matn2);
}
```

to use this you most copy function in your code . 
in next step you most set vss and rw pin of lcd to ground .
# more features 
if you need to balance lcd light you can use a potanciometer and connect it to vee pin of arduino.
and then connect vdd to 5v battery .