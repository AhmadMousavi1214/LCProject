#include "QuadSevenSegment.h"

// Use Library and pins initilize
int pin[11] = {7, 6, 5, 4, 3, 2, 1, 13, 12, 11, 10};
QuadSevenSegment segment(pin);

// for start internal timer
 unsigned long current_time;
 unsigned long last_1Sec = 0;
  unsigned long last_5Sec = 0;
 
 String pass = "";

 // example number, inserted to segment
 int _step = 0;
 
void setup() {
  
}

void loop() {
  // Update Internal Timer
  current_time = millis();
  
  segment.DisplayPass(pass);
  if(current_time - last_1Sec > 1000){
    pass += String(_step);
    last_1Sec = current_time;
  }

  if(current_time - last_5Sec > 5000){
    _step += 1;
    if(_step > 9) _step = 0;
    pass = "";
    last_5Sec = current_time;
  }
 }
    
