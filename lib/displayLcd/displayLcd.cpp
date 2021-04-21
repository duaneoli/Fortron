#include "Arduino.h"
#include "displayLcd.h"
#include "Wire.h"
#include "LiquidCrystal.h"

String s1 = "Duane";
String s2 = "Leticia";
String *pointer;

DisplayLcd::DisplayLcd(uint8_t end,uint8_t col, uint8_t lin){
    this->lcd = new LiquidCrystal_I2C(end,col,lin);
    this->col = col;
    this->lin = lin;
}

void DisplayLcd::setCustomChar(){
    byte grauss[8] = {0x07,0x05,0x07,0x00,0x07,0x00,0x00,0x00};
    byte seta[8] = {0x00,0x04,0x0E,0x15,0x04,0x04,0x04,0x00};
    this->lcd->createChar(0,grauss);
    this->lcd->createChar(1,seta);
}

void DisplayLcd::init(){
    this->lcd->begin();
    this->setCustomChar();
    this->lcd->backlight();
    this->lcd->clear();
    pointer = &s1;
    this->setStartValue(*pointer,0);
    pointer = &s2;
    this->setStartValue(*pointer,1);    
}
void DisplayLcd::setStartValue(String s,uint8_t lin){
    this->lcd->setCursor(0,lin);
    this->lcd->print(s);
}
void DisplayLcd::setCenterValue(String s,uint8_t lin,uint8_t displacement){
    int total = s.length()+displacement;
    this->lcd->setCursor(colStartCenter(total),lin);
    this->lcd->print(s);
}
void DisplayLcd::setEndValue(String s,uint8_t lin,uint8_t displacement){
    int total = s.length()+displacement;
    this->lcd->setCursor(colStartEnd(total),lin);
    this->lcd->print(s);
}
void DisplayLcd::write(uint8_t c){
    this->lcd->write(c);
}
void DisplayLcd::print(String s){
    this->lcd->print(s);
}
void DisplayLcd::clear(){
    this->lcd->clear();
}
void DisplayLcd::backlight(boolean b){
    if(b){
        this->lcd->backlight();
    }else{
        this->lcd->noBacklight();
    }
}