#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <BCDsegment.h>

using namespace std;

//amade sazi lcd;
int adad_khali = 1000000;
bool matnbede = true ; 
String matn = "adadi nazadid";
int adad = adad_khali ; 
String matn_adad = ""; 
bool taghir = false;

const String matn_success = "ramz sahih ast";
const String matn_fail = "ramz nadorost";

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// amade sazi klid ha ; 
const byte ROWS = 4;
const byte COLS = 3;
String password = "0000";
String tashih_ramz = "";
//0=hanooz nazade ya dare mizane , 1=dorost zade , 2=dare avaz mikone , 3=dare bar dovvom mizane; 
int vaziat = 0 ; 

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


void namayesh(bool matn_bede , bool adad_bede , String matn , String adad)
{
    lcd.clear();
    lcd.setCursor(0,0);
    if(matn_bede)
    {
      lcd.print(matn);
      lcd.setCursor(1, 1);
    }
    if(adad!=adad_khali)
    {
      if(adad_bede)
      {
        lcd.print(matn_adad);
      }
    }
    displaypass(matn);
}

void setup() {
  Serial.begin(9600);
}


void printDigits(String enteredDigits) {
  Serial.println(enteredDigits);
}


void loop() {
  char key = keypad.getKey();

  if (key) {
    //hazf kardan;
    if (key == '*') 
    {
      //agar dasht mizad ya taghir midad ya tayid mikard taghir yani agar halat dorost zadan nabood ; 
      if(vaziat!=1)
      {
        if(enteredDigits.length() > 0) 
        {
          enteredDigits.remove(enteredDigits.length() - 1);
          printDigits(enteredDigits);
        } 
        else 
        {
          // here we have to show the error message to the lcd  (after inpelimenting that) !
          Serial.println("the digits are not enough to delete them !");
        }
      }
    } 
    else if (key == '#') 
    {
      //agar hanooz ramz tayid shode nazade; 
      if(!vaziat)
      {
        // agar 
        // if (enteredDigits.length() == 4) {
        printDigits(enteredDigits);
        // here we have to process thee the way that we want ot check is the entered digit is the same as password or not !
        // something like this imelimenation
        if (enteredDigits == password) 
        {
          Serial.println("you entered the correct password !");
          namayesh(true , true , matn_success , enteredDigits );
          // taghir state ;
          vaziat = 1 ; 
        } 
        else 
        {
          Serial.println("you didnt entered the correct answer !");
          namayesh(true , false , matn_fail , enteredDigits );
        }
        // }
        // else 
        // {
        //   // here we have to say again in lcd you have not enough digit for analysing the password you entered !
        //   Serial.println("digits are not enough to check !");
        // }
      }
      // dorost zade ;
      else if (vaziat == 1)
      {
        namayesh(true , false , "ramz jadid" , "" );
        vaziat = 2 ; 
        enteredDigits="" ;
      }
      else if (vaziat == 2)
      {
        namayesh(true , false , "tayid konid" , "");
        ramz_tashih = enteredDigits ;
        enteredDigits="" ;
      }
      else if (vaziat==3)
      {
        if (enteredDigits==ramz_tashih)
        {
          namayesh(true , false , "taghir yaft" , "");
          vaziat = 2 ; 
        }
        else 
        {
          namayesh(true , false , matn_fail , "");
          ramz_tashih= "" ;
        }  
        enteredDigits= "" ;
      }
    } 
    else 
    {
      if (enteredDigits.length() >= 4) {
        // correct message in the lcd !
        Serial.println("you cant enter more than four digits !");
        namayesh(true , false , "over flow" , "");
        enteredDigits = "" ; 
      } 
      else 
      {
        if(vaziat!=1)
        {
          enteredDigits += key ;
          printDigits(enteredDigits);
          namayesh(false , true , "" , enteredDigits);
        }
      }
    }
  }
}
