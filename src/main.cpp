#include <Arduino.h>
#include "fourDisplaySeg.h"
#include "timer.h"
#include "displayLcd.h"
#include "DS1307.h"
#include "chess.h"
#include "ultrasonic.h"
#include "mpu6050.h"
#include "bmp280.h"
#include "task.h"
#include "controller.h"

const uint8_t button1 = 17;
const uint8_t button2 = 5;
const uint8_t button3 = 34;

char core0task;
String temp;
boolean inConfig;
TaskHandle_t Core0;
TaskHandle_t Core1;

BMP280* bmp = new BMP280(); // I2C
MPU6050 mpu(0x69);
Ultrasonic* ultrasonic = new Ultrasonic(18,19);
DS1307 *rtc = new DS1307();
DisplayLcd* displayLcd = new DisplayLcd(0x27,16,2);
                //a,b,c,d,e,f,g,p
byte letras[8] = {13,12,14,27,26,25,33,32};
                //1,2,3,4 
byte fourSeg[4] = {15,2,4,16};
FourDisplaySeg* fourDisplay = new FourDisplaySeg(letras,fourSeg,0);
TimerRegress* timer = new TimerRegress();
ChessClock *chess = new ChessClock(button1,button3);
TaskCore *task = new TaskCore(fourDisplay,chess,timer,bmp,ultrasonic,button1,button2,button3);
Controller* controller = new Controller(displayLcd,rtc,button1,button2,button3);

void core0loop(void * pvParameters){
  while(1){
    switch(controller->getTask(0)){
      case 1:
        task->playChess(controller->getTimeChess());
        controller->resetTask(0);
      break;
      case 2:
        task->chronometer(controller->getTimeChonometer());
        controller->resetTask(0);
      break;
      case 3:
        while(1){
          task->showTemp(bmp->getTemperatura(controller->getUniTemp()),controller->getUniTemp());
            if(digitalRead(button2) && !inConfig) {
              fourDisplay->circular(10);
              break;
            }
        }
        controller->resetTask(0);
      break;
      case 4:
        while(1){
          ultrasonic->read();
          task->showDistance(ultrasonic->getDistance(controller->getUniUltra()));
          if(digitalRead(button2) && !inConfig) {
            fourDisplay->circular(10);
            break;
          }
        }
        controller->resetTask(0);
      break;
      default:
        delay(10);
      break;
    }
    delay(10);
  }

} 
void core1loop(void * pvParameters){
    displayLcd->clear();
    unsigned long time = 0;
    unsigned long timeDisplay = 0;
    bmp->read();
    rtc->update();
    mpu.read();
    while(1){
      if(digitalRead(button1) && digitalRead(button3) && core0task!=1 && core0task != 2){
          inConfig = true;
          controller->config();
          inConfig = false;
          displayLcd->clear();
      }
      if(millis()-timeDisplay>1000){
      displayLcd->clear();
      displayLcd->setStartValue(rtc->getFullTime(),0);
      displayLcd->setEndValue(String(bmp->getTemperatura(controller->getUniTemp())),0,2);
      displayLcd->write(0);
      if(controller->getUniTemp()){
        displayLcd->print("C");
      }else{
        displayLcd->print("F");
      }
      displayLcd->setStartValue(rtc->getFullDate(),1);
      displayLcd->setEndValue(String(bmp->getAltitude(controller->getUniAlti())),1,1);
      if(controller->getUniAlti()){
        displayLcd->print("m");
      }else{
        displayLcd->print("f");
      }
        timeDisplay = millis();
      }
      if(millis()-time>500){
          bmp->read();
          rtc->update();
          mpu.read();
          time = millis();
      }
    }
}

void setup() {
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  displayLcd->init();
  Serial.begin(9600);
  bmp->begin();
  rtc->begin();
  rtc->start();
  timer->setTimer(10000);
  timer->setInitTimer();
  mpu.begin();
  mpu.start();
  xTaskCreatePinnedToCore(core0loop,"core0",10000,NULL,1,&Core0,0);
  xTaskCreatePinnedToCore(core1loop,"core1",20000,NULL,1,&Core1,1);
}
void loop() {}

