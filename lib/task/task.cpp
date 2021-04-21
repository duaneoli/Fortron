#include "Arduino.h"
#include "task.h"

TaskCore::TaskCore(FourDisplaySeg* fourDisplay, ChessClock* chess,TimerRegress* timer,BMP280* bmp,Ultrasonic* ultrasonic,uint8_t button1, uint8_t button2, uint8_t button3){
    this->fourDisplay = fourDisplay;
    this->chess = chess;
    this->button1= button1;
    this->button2 = button2;
    this->button3 = button3;
    this->timer = timer;
    this->bmp = bmp;
    this->ultrasonic = ultrasonic;
}
void TaskCore::playChess(unsigned long time){
    delay(1000);
  boolean player;
  boolean stop = false;
  while(!digitalRead(button2)){
      this->fourDisplay->circular(random(10,100));
  }
  chess->setTime(time);
  chess->setInitPlayer1();
  while(!stop){
    chess->exec(&player,&stop);
    this->fourDisplay->setStringOnDisplay(chess->getCurrentTime());
  }
  String s = " P";
  s.concat(String(player));
  s.concat(" ");
  while(1){
    if(digitalRead(button2)){
        break;
    } 
    for(int x=0;x<500;x++){
      this->fourDisplay->setStringOnDisplay(s);
    }
    this->fourDisplay->snake(50);
  }
}
void TaskCore::chronometer(unsigned long time){
    delay(1000);
  this->timer->setTimer(time);
  boolean out = false;
  boolean pause = false;
  while(!out){
    while(!digitalRead(button2)){
      if(pause){
        this->fourDisplay->setStringOnDisplay(this->timer->getString());
      }else{
        this->fourDisplay->circular(random(10,100));
      }
    }
    this->timer->setInitTimer();
    while(!out){
      this->timer->countdownClock();
      this->fourDisplay->setStringOnDisplay(this->timer->getString());
      if(digitalRead(button3)){
        this->timer->pause();
        pause = true;
        break;
      }
      if(this->timer->isStop()){
        while(1){
          this->fourDisplay->snake(random(10,100));
          if(digitalRead(button2)){
            out = true;
            break;
          }
        }
      }
    }
  }
}
void TaskCore::showTemp(float temp,boolean inCelcius){
    String ss = String(temp,1);
    if(inCelcius){
      ss.concat("C");
    }else{
      ss.concat("F");
    }
    unsigned long time = millis();
    while(millis()-time<500){
        fourDisplay->setStringOnDisplay(ss);
    }
}
void TaskCore::showDistance(float value){
    String ss = String(value,2);
    unsigned long time = millis();
    while(millis()-time<1000){
        fourDisplay->setStringOnDisplay(ss);
    }
}

