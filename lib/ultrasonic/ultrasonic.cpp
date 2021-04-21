#include "Arduino.h"
#include "ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t echo,uint8_t trig){
    this->echo = echo;
    this->trig = trig;
    pinMode(this->echo, INPUT); // Sets the echoPin as an INPUT
    pinMode(this->trig, OUTPUT); // Sets the trigPin as an OUTPUT
}
void Ultrasonic::read(){
    long duration;
    digitalWrite(this->trig, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trig, LOW);
    duration = pulseIn(this->echo, HIGH);
    this->distance = duration * 0.034 / 2;
}
float Ultrasonic::getDistance(char unidadeMedida){
    switch (unidadeMedida){
    case 1: return this->getDistanceInMillimeter(); break;
    case 2: return this->getDistanceInCentimeter(); break;
    case 3: return this->getDistanceInMeter(); break;
    case 4: return this->getDistanceInInches(); break;
    case 5: return this->getDistanceInYard(); break;
    }
}
float Ultrasonic::getDistanceInMeter(){
    return (this->distance/100.0);
}
float Ultrasonic::getDistanceInCentimeter(){
    return this->distance;
}
float Ultrasonic::getDistanceInMillimeter(){
    return (this->distance*10);
}
float Ultrasonic::getDistanceInInches(){
    return (this->distance/2.54);
}
float Ultrasonic::getDistanceInKlometer(){
    return (this->distance/100000.0);
}
float Ultrasonic::getDistanceInYard(){
    return (this->distance/91.44);
}