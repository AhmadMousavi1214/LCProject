#include"BCDsegment.h"

const int BCD[11][4]{
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
  {1,1,1,1}
};

  BCDsegment::BCDsegment(int beginPin){
    int t = beginPin;
    for(int i = 0; i < 16; i++){
      pins[i] = t;
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], LOW);
      t++;
    }
  }
  
  void BCDsegment::ClearAll(){
    for(int i = 0; i < 16; i++){
      digitalWrite(pins[i], LOW);
    }
  }
  
  void BCDsegment::DisplayDigit(int d, int lvl){
   for(int i = 0; i < 4; i++){
    digitalWrite(pins[i + (4 * lvl)], BCD[d][i]);
    delay(10);
   }
 }

 void BCDsegment::DisplayPass(String pass){
    
      while(pass.length() < 4){
        pass = pass + '*';
      }
      for(int i = 0; i < 4; i++){
        if(pass[i] != '*'){
          BCDsegment::DisplayDigit(String(pass[i]).toInt(), i);
          delay(10);
        }
        else{
          BCDsegment::DisplayDigit(10, i);
          delay(10);
        }
  }
 }
