#include "Arduino.h"
#include "timer.h"

TimerRegress::TimerRegress(){
    this->currentFirst = true;
    this->stop = false;
    this->countdown= new Countdown();
    this->defaultTimer = new DefaultTimer();
}
void TimerRegress::updateTimer(unsigned long t){
    this->defaultTimer->hours = numberOfHours(t);
    this->defaultTimer->minutes = numberOfMinutes(t);
    this->defaultTimer->seconds = numberOfSeconds(t);
}
void TimerRegress::toStringFourDisplay(){
    if(this->defaultTimer->hours>0){
      if(this->defaultTimer->hours >=10){
        this->displaySegments = String(this->defaultTimer->hours);
      }else{
        this->displaySegments = String("0"+String(this->defaultTimer->hours));
      }
      if((this->defaultTimer->seconds%2)==0){
          this->displaySegments.concat(":");
      }else{
          this->displaySegments.concat("-");
      }
      if(this->defaultTimer->minutes>=10){
          this->displaySegments.concat(String(this->defaultTimer->minutes));
      }else{
          this->displaySegments.concat(String("0"+String(this->defaultTimer->minutes)));
      }
    }else{
      if(this->defaultTimer->minutes >=10){
        this->displaySegments = String(this->defaultTimer->minutes);
      }else{
        this->displaySegments = String("0"+String(this->defaultTimer->minutes));
      }
      if((this->defaultTimer->seconds%2)==0){
          this->displaySegments.concat(":");
      }else{
          this->displaySegments.concat("-");
      }
      if(this->defaultTimer->seconds>=10){
          this->displaySegments.concat(String(this->defaultTimer->seconds));
      }else{
          this->displaySegments.concat(String("0"+String(this->defaultTimer->seconds)));
      }
    }
}
int TimerRegress::getHours(){
    return this->defaultTimer->hours;
}
int TimerRegress::getMinutes(){
    return this->defaultTimer->minutes;
}
int TimerRegress::getSeconds(){
    return this->defaultTimer->seconds;
}
String TimerRegress::getString(){
  return this->displaySegments;
}
void TimerRegress::setInitTimer(){
  this->countdown->init = millis();
}
void TimerRegress::setTimer(unsigned long t){
    this->countdown->time = t;
    this->countdown->timeRequest = t;
    this->countdown->lastSeconds = numberOfSeconds(t);
    this->stop = false;
}
void TimerRegress::countdownClock(){
  if(this->countdown->time <= 0){
    this->stop = true;
    this->countdown->time = 0;
  }else{
    this->countdown->time = this->countdown->timeRequest - (millis()-this->countdown->init);
    this->updateTimer(this->countdown->time/1000);
    this->toStringFourDisplay();
  }
}
boolean TimerRegress::isStop(){
  return this->stop;
}
void TimerRegress::pause(){
  this->countdown->timeRequest = this->countdown->time;
}

