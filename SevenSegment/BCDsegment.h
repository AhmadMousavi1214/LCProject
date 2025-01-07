#ifndef BCDsegment_h
#define BCDsegment_h

#include "Arduino.h"

class BCDsegment {
  public:
    BCDsegment(int beginPin);
    void DisplayPass(String pass);
  private:
    int pins[16];
    void ClearAll();
    void DisplayDigit(int d, int lvl);
};

#endif
