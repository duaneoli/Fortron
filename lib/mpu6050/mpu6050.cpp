#include "Arduino.h"
#include "mpu6050.h"

MPU6050::MPU6050(uint8_t Address){
    this->Address = Address;
    this->currentDate = new Date();
    this->currentDate->accelerometer = new Coordinates();
    this->currentDate->gyroscope = new Coordinates();
    this->lastDate = new Date();
    this->lastDate->accelerometer = new Coordinates();
    this->lastDate->gyroscope = new Coordinates();
}
void MPU6050::begin(){
    Wire.begin();
    Wire.beginTransmission(this->Address);
    Wire.write(0x6B);
}
void MPU6050::start(){
    Wire.write(0); 
    Wire.endTransmission(true);
}
void MPU6050::read(){ 
    Wire.beginTransmission(this->Address);
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(this->Address,14,true); 
    this->saveLastAccelerometer();
    this->currentDate->accelerometer->x=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
    this->currentDate->accelerometer->y=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    this->currentDate->accelerometer->z=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    this->currentDate->temp=Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    this->currentDate->gyroscope->x=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    this->currentDate->gyroscope->y=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    this->currentDate->gyroscope->z=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}
void MPU6050::getAccelerometer(String *s){
    String r = String((this->currentDate->accelerometer->x));
    r.concat("-");
    r.concat(String((this->currentDate->accelerometer->y)));
    r.concat("-");
    r.concat(String((this->currentDate->accelerometer->z)));
    *s = r;
}
void MPU6050::getLastAccelerometer(String *s){
    String r = String();
    r.concat("-");
    r.concat(String((this->lastDate->accelerometer->x)-(this->currentDate->accelerometer->x)));
    r.concat("-");
    r.concat(String((this->lastDate->accelerometer->x)-(this->currentDate->accelerometer->x)));
    *s = r;
}
void MPU6050::saveLastAccelerometer(){
    this->lastDate->accelerometer->x = this->currentDate->accelerometer->x;
    this->lastDate->accelerometer->y = this->currentDate->accelerometer->y;
    this->lastDate->accelerometer->z = this->currentDate->accelerometer->z; 
}
void MPU6050::getAccelerometerX(String *s){
    *s = String(abs((this->lastDate->accelerometer->x)-(this->currentDate->accelerometer->x)));
}
void MPU6050::getAccelerometerY(String *s){
    *s = String(abs((this->lastDate->accelerometer->y)-(this->currentDate->accelerometer->y)));
}
void MPU6050::getAccelerometerZ(String *s){
    *s = String(abs((this->lastDate->accelerometer->z)-(this->currentDate->accelerometer->z)));
}

void MPU6050::getGyroscope(String *s){
    String r = String((this->currentDate->gyroscope->x));
    r.concat("-");
    r.concat(String((this->currentDate->gyroscope->y)));
    r.concat("-");
    r.concat(String((this->currentDate->gyroscope->z)));
    *s = r;
}
void MPU6050::getLastGyroscope(String *s){
    String r = String();
    r.concat("-");
    r.concat(String((this->lastDate->gyroscope->x)-(this->currentDate->gyroscope->x)));
    r.concat("-");
    r.concat(String((this->lastDate->gyroscope->x)-(this->currentDate->gyroscope->x)));
    *s = r;
}
void MPU6050::saveLastGyroscope(){
    this->lastDate->gyroscope->x = this->currentDate->gyroscope->x;
    this->lastDate->gyroscope->y = this->currentDate->gyroscope->y;
    this->lastDate->gyroscope->z = this->currentDate->gyroscope->z; 
}
void MPU6050::getGyroscopeX(String *s){
    *s = String(abs((this->lastDate->gyroscope->x)-(this->currentDate->gyroscope->x)));
}
void MPU6050::getGyroscopeY(String *s){
    *s = String(abs((this->lastDate->gyroscope->y)-(this->currentDate->gyroscope->y)));
}
void MPU6050::getGyroscopeZ(String *s){
        *s = String(abs((this->lastDate->gyroscope->z)-(this->currentDate->gyroscope->z)));
}