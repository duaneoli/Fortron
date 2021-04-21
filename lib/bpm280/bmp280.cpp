#include "Arduino.h"
#include "bmp280.h"

BMP280::BMP280(){
    this->bmp = new Adafruit_BMP280();
}
boolean BMP280::begin(){
    if (!this->bmp->begin()) {
            Serial.println(F("Could not find a valid BMP280 sensor, check wiring o try a different address!"));
            return false;
    }else{
        this->bmp->setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
        return true;
    }
}
void BMP280::read(){
    this->temperatura = this->bmp->readTemperature();
    this->altitude = this->bmp->readAltitude(1013.25);
    this->pressao = this->bmp->readPressure();
}
float BMP280::getPressure(boolean inPascal){
    if(inPascal){
        return this->pressao;
    }else{
        return (this->pressao/101325);
    }
}
float BMP280::getTemperatura(boolean inCelsius){
    if(inCelsius){
        return this->temperatura;
    }else{
        return ((this->temperatura*(9/5))+32);
    }
}
float BMP280::getAltitude(boolean inMeter){
    if(inMeter){
        return this->altitude;
    }else{
        return (this->altitude*3.2881);
    }
}

