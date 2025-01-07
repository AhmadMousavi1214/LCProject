#include "BCDsegment.h"

BCDsegment segment = BCDsegment(22);
 int a = 0;
void setup() {
 
}

void loop() {
  segment.DisplayPass(String(a));
  delay(1000);
  a+= 2;
  if(a >= 6789 + 1111){
    a = 0;
  }
 }
    
