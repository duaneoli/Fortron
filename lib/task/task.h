#ifndef _TESK_
#define _TESK_
#include "fourDisplaySeg.h"
#include "chess.h"
#include "timer.h"
#include "bmp280.h"
#include "ultrasonic.h"

class TaskCore{
    private:
    FourDisplaySeg* fourDisplay;
    ChessClock* chess;
    TimerRegress* timer;
    BMP280* bmp;
    Ultrasonic* ultrasonic;
    uint8_t button1;
    uint8_t button2;
    uint8_t button3;
    public:
    TaskCore(FourDisplaySeg* fourDisplay,ChessClock* chess,TimerRegress* timer,BMP280* bmp,Ultrasonic* ultrasonic,uint8_t button1, uint8_t button2, uint8_t button3);
    void playChess(unsigned long time);
    void chronometer(unsigned long time);
    void showTemp(float temp,boolean inCelcius);
    void showDistance(float value);
   
};

#endif