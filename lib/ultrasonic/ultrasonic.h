#ifndef _ULTRASONIC_
#define _ULTRASONIC_
#include "Arduino.h"

class Ultrasonic{
    private:
    uint8_t echo;
    uint8_t trig;
    uint8_t distance;
    public:
    Ultrasonic(uint8_t echo, uint8_t trig);
    void read();
    float getDistance(char unidadeMedida);
    float getDistanceInMeter();
    float getDistanceInCentimeter();
    float getDistanceInMillimeter();
    float getDistanceInInches();
    float getDistanceInKlometer();
    float getDistanceInYard();
};

#endif