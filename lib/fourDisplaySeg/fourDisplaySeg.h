#ifndef fourDisplaySeg
#define fourDisplaySeg

#include "Arduino.h"

class FourDisplaySeg{
    private:
    byte letras[8];
    byte fourSeg[4];
    byte pp;
    unsigned int delayBetween;
    public:
    FourDisplaySeg(byte letras[8],byte fourSeg[4], byte pp);
    void setCaracter(char letra);
    void setDisplay(char numberDisplay);
    void setStringOnDisplay(String fourDisplay);
    void clockWithTwePointer(char oneDigit, char twoDigit, char threeDigit, char fourDigit, boolean twoPointer);
    void circular(int timeDelay);
    void snake(int timeDelay);
};

#endif