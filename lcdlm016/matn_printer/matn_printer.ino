/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int adad_khali = 1000000;
bool matnbede = true ; 
String matn = "adadi nazadid";
int adad = adad_khali ; 
String matn_adad = ""; 
bool taghir = false;

const String matn_success = "ramz sahih ast";
const String matn_fail = "ramz nadorost";
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);




void tabe(bool aya_matn_bedam , bool sehat , int n )
{
  taghir = true ; 
  if(aya_matn_bedam)
  {
    if(sehat)
    {
      matn=matn_success;
    }
    else
    {
      matn = matn_fail ; 
    }
  }
  adad = n ; 
}


void tabe(bool aya_matn_bedam , bool sehat , String n )
{
  taghir = true;
  if(aya_matn_bedam)
  {
    if(sehat)
    {
      matn=matn_success;
    }
    else
    {
      matn = matn_fail ; 
    }
  }
  matn_adad = n ; 
}


void namayesh(bool matn_bede , bool adad_bede , String matn , String adad)
{
  // if(taghir)
  // {
    lcd.clear();
    lcd.setCursor(0,0);
    if(matn_bede)
    {
      lcd.print(matn);
      lcd.setCursor(1, 1);
    }
    // else
    // {
    //   if(adad!=adad_khali)
    //   {
    //     lcd.setCursor(0,0);
    //     lcd.print(matn_adad);
    //   }
    // }
    if(adad!=adad_khali)
    {
      if(adad_bede)
      {
        lcd.print(matn_adad);
      }
    }
    // print the number of seconds since reset:
    // taghir = false ; 
  // }
}

void namayesh()
{
  if(taghir)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    if(matnbede)
    {
      lcd.print(matn);
      if(adad!=adad_khali)
      {
        lcd.setCursor(0,1);
        lcd.print(matn_adad);
      }
    }
    else
    {
      if(adad!=adad_khali)
      {
        lcd.setCursor(0,0);
        lcd.print(matn_adad);
      }
    }
    // print the number of seconds since reset:
    taghir = false ; 
  }
}


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(matn);
  // // Print a message to the LCD.
  // lcd.print("hello, world!");
  adad = 0;
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // if(taghir)
  // {
  //   lcd.clear();
  //   lcd.setCursor(0,0);
  //   if(matnbede)
  //   {
  //     lcd.print(matn);
  //     if(adad!=adad_khali)
  //     {
  //       lcd.setCursor(0,1);
  //       lcd.print(adad);
  //     }
  //   }
  //   else
  //   {
  //     if(adad!=adad_khali)
  //     {
  //       lcd.setCursor(0,0);
  //       lcd.print(adad);
  //     }
  //   }
  //   // print the number of seconds since reset:
  //   taghir = false ; 
  // }
  namayesh(true , true , matn_success , matn_adad);
  adad+=1;
  // matn_adad=Serial.println(adad);
  matn_adad = adad;
  delay(500);
  // tabe(true , true , "0000" );

}

