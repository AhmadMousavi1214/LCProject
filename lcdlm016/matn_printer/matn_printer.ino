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

// ettesalat mored niaz lcd .
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
}

//matn1 ra dar khat avval va matn2 ra dar khat 2 minevisad . 
void namayesh(String matn1 , String matn2="")
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(matn1);
    lcd.setCursor(0,1);
    lcd.print(matn2);
}


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(matn);
  adad = 0;
}

void loop() {
  namayesh(matn_success , matn_adad);
  adad+=1;
  matn_adad = adad;
  delay(500);
}