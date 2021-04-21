#ifndef _BPM280_
#define _BPM280_
#include "Arduino.h"
#include "Adafruit_BMP280.h"
#include "Wire.h"

class BMP280{
    private:
    Adafruit_BMP280* bmp; // I2C
    float temperatura;
    float altitude;
    float pressao;
    public:
    BMP280();
    boolean begin();
    void read();
    float getPressure(boolean inPascal);
    float getTemperatura(boolean inCelsius);
    float getAltitude(boolean inMeter);
};

#endif 