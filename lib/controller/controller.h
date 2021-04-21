#ifndef _CONTROLLER_
#define _CONTROLLER_
#include "Arduino.h"
#include "displayLcd.h"
#include "DS1307.h"

struct TaskCores{
  char taskCoreZero;
  char taskCoreOne;
};

struct BmpSensor{
  boolean tempInCelsius;
  boolean altitudeInMeter;
  boolean pressureInPascal;
};

struct fullTimeR{
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
};

struct fullDateR{
  uint8_t dayName;
  uint8_t day;
  uint8_t month;
  uint16_t year; 
};


class Controller{
    private:
    DisplayLcd* displayLcd;
    uint8_t button1;
    uint8_t button2;
    uint8_t button3;
    TaskCores* taskCores;
    BmpSensor* bmpSensor;
    DS1307* rtc;
    char ultrasonicUniMedida;
    unsigned long timeChronometer;
    unsigned long timeClockChess;
    char *taskCore0;
    char configSize[10] = {0,2,2,3,3,3,6,1,1,2};
    char *configList [10][8] = {{"Voltar"},
                                {"Chess","Executar","Alter Tempo"},
                                {"Chronometer","Executar","Alter Tempo"},
                                {"Temperatura","Executar","Celsius","Fahrenheit"},
                                {"Altitude","Executar","Metter","Feet"},
                                {"Presao","Executar","Pascal","Atm"},
                                {"Distancia","Executar","Millimiter","Centimeter","Metro","Inches","Yard"},
                                {"Giroscopio","Executar"},
                                {"Acelerometro","Executar"},
                                {"RTC","Alterar Hora","Alterar Data"}};
    public:
    fullTimeR* fullTime;
    fullDateR* fullDate;
    Controller(DisplayLcd* displayLcd,DS1307* rtc,uint8_t button1,uint8_t button2,uint8_t button3);
    void config();
    int getTask(char core);
    void resetTask(char core);
    int subMenu(int menu,int submenu);
    void setFunction(int menu,int submenu);
    char getUniUltra();
    void alterTimer(unsigned long* time);
    int getfulltimeHoras();
    int getfulltimeMinutes();
    int getfulltimeSeconds();
    unsigned long getTimeChess();
    unsigned long getTimeChonometer();
    boolean getUniTemp();
    boolean getUniAlti();
    boolean getUniPress();
    void alterarHora();
    void alterarData();
};

#endif