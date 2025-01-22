#include"QuadSevenSegment.h"

  QuadSevenSegment::QuadSevenSegment(int _pins[11]){
    for(int i = 0; i < 7; i++){
      pins[i] = _pins[i];
      pinMode(_pins[i], OUTPUT);
    }
    for(int i = 0; i < 4; i++){
      multiplexerPins[i] = _pins[i+7];
      pinMode(multiplexerPins[i], OUTPUT); 
      digitalWrite(multiplexerPins[i], HIGH);
    }

    IsDisplay = true;
  }
  
  void QuadSevenSegment::Clear(){
    for(int i = 0; i < 7; i++){
      digitalWrite(pins[i], LOW);
    }
  }
  
  void QuadSevenSegment::DisplayDigit(char digit){
    switch(digit){
      case '0':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[4], HIGH);
        digitalWrite(pins[5], HIGH);

        digitalWrite(pins[6], LOW);
        
        break;
      }
      case '1':{
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);

        digitalWrite(pins[0], LOW);
        digitalWrite(pins[3], LOW);
        digitalWrite(pins[4], LOW);
        digitalWrite(pins[5], LOW);
        digitalWrite(pins[6], LOW);
        
        break;
      }
      case '2':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[6], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[4], HIGH);

        digitalWrite(pins[2], LOW);
        digitalWrite(pins[5], LOW);
        
        break;
      }
      case '3':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[6], HIGH);

        digitalWrite(pins[4], LOW);
        digitalWrite(pins[5], LOW);
        
        break;
      }
      case '4':{
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[5], HIGH);
        digitalWrite(pins[6], HIGH);

        digitalWrite(pins[3], LOW);
        digitalWrite(pins[4], LOW);
        digitalWrite(pins[0], LOW);
        
        break;
      }
      case '5':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[5], HIGH);
        digitalWrite(pins[6], HIGH);

        digitalWrite(pins[1], LOW);
        digitalWrite(pins[4], LOW);
        
        break;
      }
      case '6':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[4], HIGH);
        digitalWrite(pins[5], HIGH);
        digitalWrite(pins[6], HIGH);

        digitalWrite(pins[1], LOW);
        
        
        break;
      }
      case '7':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);

        digitalWrite(pins[3], LOW);
        digitalWrite(pins[4], LOW);
        digitalWrite(pins[5], LOW);
        digitalWrite(pins[6], LOW);
        
        break;
      }
      case '8':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[4], HIGH);
        digitalWrite(pins[5], HIGH);
        digitalWrite(pins[6], HIGH);
        
        break;
      }
      case '9':{
        digitalWrite(pins[0], HIGH);
        digitalWrite(pins[1], HIGH);
        digitalWrite(pins[2], HIGH);
        digitalWrite(pins[3], HIGH);
        digitalWrite(pins[5], HIGH);
        digitalWrite(pins[6], HIGH);

        digitalWrite(pins[4], LOW);
        break;
      }
      default:{
        QuadSevenSegment::Clear();
      }
    }
 }

 void QuadSevenSegment::SegmentSelector(int segment){
  for(int i = 0; i < 4; i++){
    digitalWrite(multiplexerPins[i], HIGH);
  }
  digitalWrite(multiplexerPins[segment], LOW);
 }

  void QuadSevenSegment::Stop(){
    IsDisplay = false;
  }
  void QuadSevenSegment::Start(){
    IsDisplay = true;
  }

 void QuadSevenSegment::DisplayPass(String pass){
    IsDisplay = true;
    if(IsDisplay){
      while(pass.length() < 4){
        pass = pass + '*';
      }
      for(int i = 0; i < 4; i++){
      SegmentSelector(i);
      DisplayDigit(pass[i]);
      delay(1);
  }
  }
 }
