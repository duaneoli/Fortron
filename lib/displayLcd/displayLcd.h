#ifndef _DISPLAYLCD_
#define _DISPLAYLCD_
#include "Arduino.h"
#include "Wire.h"
#include "LiquidCrystal.h"

#define colStartCenter(_length_) (8 - (_length_ / 2))
#define colStartEnd(_length_) (16 - _length_)

class DisplayLcd{
    private:
    LiquidCrystal_I2C* lcd;
    uint8_t col;
    uint8_t lin;
    public:
    DisplayLcd(uint8_t end,uint8_t col, uint8_t lin);
    void init();
    void setCustomChar();
    void setStartValue(String s,uint8_t lin);
    void setCenterValue(String s,uint8_t lin,uint8_t displacement);
    void setEndValue(String s,uint8_t lin,uint8_t displacement);
    void backlight(boolean b);
    void clear();
    void write(uint8_t c);
    void print(String s);
};

#endif