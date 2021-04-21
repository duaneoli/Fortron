#ifndef _MPU6050_
#define _MPU6050_
#include "Arduino.h"
#include "Wire.h"

struct Coordinates{
    int x;
    int y;
    int z;
};

struct Date{
    Coordinates* accelerometer;
    Coordinates* gyroscope;
    int temp;
};

class MPU6050{
    private:
    uint8_t Address;
    Date* currentDate;
    Date* lastDate;
    public:
    MPU6050(uint8_t Address);
    void begin();
    void start();
    void read();
    void saveLastAccelerometer();
    void getAccelerometerX(String *s);
    void getAccelerometerY(String *s);
    void getAccelerometerZ(String *s);
    void getAccelerometer(String *s);
    void getLastAccelerometer(String *s);

    void saveLastGyroscope();
    void getGyroscopeX(String *s);
    void getGyroscopeY(String *s);
    void getGyroscopeZ(String *s);
    void getGyroscope(String *s);
    void getLastGyroscope(String *s);
};

#endif