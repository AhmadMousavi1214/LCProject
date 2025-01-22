#ifndef QuadSevenSegment_h
#define QuadSevenSegment_h

#include "Arduino.h"

class QuadSevenSegment {
  public:
    QuadSevenSegment(int _pins[11]);
    void DisplayPass(String pass);
    void Stop();
    void Start();
  private:
    int pins[7];
    int multiplexerPins[4];
    bool IsDisplay;
    void Clear();
    void SegmentSelector(int segment);
    void DisplayDigit(char digit);
};

#endif
