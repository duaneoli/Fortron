#include "Arduino.h"
#include "controller.h"



Controller::Controller(DisplayLcd* displayLcd,DS1307* rtc,uint8_t button1,uint8_t button2,uint8_t button3){
    this->displayLcd = displayLcd;
    this->button1 = button1;
    this->button2 = button2;
    this->button3 = button3;
    this->taskCore0 = taskCore0;
    this->taskCores = new TaskCores();
    this->bmpSensor = new BmpSensor();
    this->bmpSensor->tempInCelsius = true;
    this->bmpSensor->altitudeInMeter = true;
    this->bmpSensor->pressureInPascal = true;
    this->ultrasonicUniMedida = 2;
    this->timeChronometer = 15000;
    this->timeClockChess = 20000;
    this->fullTime = new fullTimeR();
    this->fullDate = new fullDateR();
    this->rtc = rtc;
}
unsigned long Controller::getTimeChess(){
  return this->timeClockChess;
}
unsigned long Controller::getTimeChonometer(){
  return this->timeChronometer;
}
void Controller::config(){
  int menu = 0;
  int submenu = 0;
  boolean inConfig = true;
  unsigned long timeDelay = 0;
  while(inConfig){
    this->displayLcd->clear();
    if((menu-1)<0){
      this->displayLcd->setStartValue(this->configList[0][0],0);
      this->displayLcd->write(0b00100000);
      this->displayLcd->write(1);
      this->displayLcd->setEndValue("*",0,0);
      this->displayLcd->setStartValue(this->configList[1][0],1);
    }else{
      this->displayLcd->setStartValue(this->configList[menu-1][0],0);
      this->displayLcd->setStartValue(this->configList[menu][0],1);
      this->displayLcd->setEndValue("*",1,0);
    }
    timeDelay = millis();
    while(millis()-timeDelay<1000){
      if(digitalRead(this->button1) && menu > 0){
        menu--;
        break;
      }
      if(digitalRead(this->button3) && menu<9){
        menu++;
        break;
      }
      if(digitalRead(this->button2)){
          if(menu != 0){
            int a = this->subMenu(menu,submenu);
            if(a == 1){
                inConfig = false;
            }
            break;
          }else{
              inConfig = false;
              break;
          }
      }
      delay(10);
    }
  }
}

int Controller::subMenu(int menu,int submenu){
  boolean outSubMenu = false;
  unsigned long timeDelay = 0;
  while(!outSubMenu){
    this->displayLcd->clear();
    if((submenu-1)<0){
      this->displayLcd->setStartValue(this->configList[menu][0],0);
      this->displayLcd->write(0b00100000);
      this->displayLcd->write(1);
      this->displayLcd->setEndValue("*",0,0);
      this->displayLcd->setStartValue(this->configList[menu][1],1);
    }else{
      this->displayLcd->setStartValue(this->configList[menu][submenu-1],0);
      this->displayLcd->setStartValue(this->configList[menu][submenu],1);
      this->displayLcd->setEndValue("*",1,0);
    }
    timeDelay = millis();
    while(millis()-timeDelay<1000){
      if(digitalRead(button1) && submenu > 0){
        submenu--;
        break;
      }
      if(digitalRead(button3) && submenu<configSize[menu]){
        submenu++;
        break;
      }
      if(digitalRead(button2)){
        if(submenu != 0){
            this->setFunction(menu,submenu);
            delay(100);
        }
        outSubMenu = true;
        break;
      }
    delay(10);
    }
  }
  return submenu;
}

void Controller::setFunction(int menu,int submenu){
    switch(menu){
        case 1:
            switch(submenu){
                case 1: //exec chess
                    if(this->taskCores->taskCoreZero == 0){
                        this->taskCores->taskCoreZero = 1;
                    }
                break;
                case 2:
                  this->alterTimer(&this->timeClockChess);
                break;
            }
        break;
        case 2:
            switch(submenu){
                case 1: //exec chonometter
                    if(this->taskCores->taskCoreZero == 0){
                        this->taskCores->taskCoreZero = 2;
                    }
                break;
                case 2: //temporizador
                  this->alterTimer(&this->timeChronometer);
                break;
            }
        break;
        case 3:
            switch(submenu){
                case 1: //exec temperatura
                    if(this->taskCores->taskCoreZero == 0){
                        this->taskCores->taskCoreZero = 3;
                    }
                break;
                case 2: //altera para celsius
                    this->bmpSensor->tempInCelsius = true;
                break;
                case 3: //altera para Fahrenheit
                    this->bmpSensor->tempInCelsius = false;
                break;
            }
        break;
        case 4:
            switch (submenu){
                case 1://exec altitude
                break;
                case 2://muda para metro
                    this->bmpSensor->altitudeInMeter = true;
                break;
                case 3://muda para passo
                    this->bmpSensor->altitudeInMeter = false;
                break;
            }
        break;
        case 5:
            switch (submenu){
                case 1://exec pressao
                break;
                case 2://muda pascal
                  this->bmpSensor->pressureInPascal = true;
                break;
                case 3://muda atm
                  this->bmpSensor->pressureInPascal = false;
                break;
            }
        break;
        case 6:
            switch (submenu){
                case 1://exec distancia
                    if(this->taskCores->taskCoreZero == 0){
                        this->taskCores->taskCoreZero = 4;
                    }
                break;
                case 2://muda millimetros
                  this->ultrasonicUniMedida = 1;
                break;
                case 3://muda centimetros
                  this->ultrasonicUniMedida = 2;
                break;
                case 4://muda metros
                  this->ultrasonicUniMedida = 3;
                break;
                case 5://muda polegadas
                  this->ultrasonicUniMedida = 4;
                break;
                case 6://muda jardas
                  this->ultrasonicUniMedida = 5;
                break;
            }
        break;
        case 7:
            //exec giroscopio
        break;
        case 8:
            //exec acelerometro
        break;
        case 9:
            switch(submenu){
              case 1:
                alterarHora();
              break;
              case 2:
                  alterarData();
              break;
            }
        break;
    }
}

int Controller::getTask(char core){
  if(core == 0){
    return this->taskCores->taskCoreZero;
  }else{
    return this->taskCores->taskCoreOne;
  }
}
void Controller::resetTask(char core){
  if(core == 0){
    this->taskCores->taskCoreZero = 0;
  }else{
    this->taskCores->taskCoreOne = 0;
  }
}
boolean Controller::getUniTemp(){
  return this->bmpSensor->tempInCelsius;
}
boolean Controller::getUniAlti(){
  return this->bmpSensor->altitudeInMeter;
}
boolean Controller::getUniPress(){
  return this->bmpSensor->pressureInPascal;
}
char Controller::getUniUltra(){
  return this->ultrasonicUniMedida;
}
void Controller::alterTimer(unsigned long * saveTime){
  int time[3] = {0,0,0};
  int pos = 0;
  boolean out = false;
  String s;
  while(!out){
      delay(100);
      s = String(time[0]);
      s.concat(":");
      s.concat(String(time[1]));
      s.concat(":");
      s.concat(String(time[2]));
      displayLcd->clear();
      displayLcd->setCenterValue("Tempo:",0,0);
      displayLcd->setCenterValue(s,1,0);
      if(digitalRead(button2)){
        if(pos<3){
          pos++;
        }else{
          out = true;
          break;
        }
      }
      if(digitalRead(button3)){
        if(pos==0){
          if(time[pos]<24){
            time[pos]++;
          }else{
            time[pos] = 0;
          }
        }else{
          if(time[pos]<60){
            time[pos]++;
          }else{
            time[pos] = 0;
          }
        }
      }
      if(digitalRead(button1)){
        if(pos==0){
          if(time[pos]>0){
            time[pos]--;
          }else{
            time[pos] = 24;
          }
        }else{
          if(time[pos]>0){
            time[pos]--;
          }else{
            time[pos] = 60;
          }
        }
      }
  }
  *saveTime = (time[0]*24*3600*1000)+(time[1]*60*1000)+(time[2]*1000);
}
int Controller::getfulltimeHoras(){
  return this->fullTime->hours;
}
int Controller::getfulltimeMinutes(){
  return this->fullTime->minutes;
}
int Controller::getfulltimeSeconds(){
  return this->fullTime->seconds;
}
void Controller::alterarHora(){
int time[3] = {rtc->getHour(),rtc->getMin(),rtc->getSeg()};
    int pos = 0;
    boolean out = false;
    String s = "";
    while(!out){
        delay(100);
        s = String(time[0]);
        s.concat(":");
        s.concat(String(time[1]));
        s.concat(":");
        s.concat(String(time[2]));
        displayLcd->clear();
        displayLcd->setCenterValue("Tempo:",0,0);
        displayLcd->setCenterValue(s,1,0);
        if(digitalRead(button2)){
          if(pos<3){
            pos++;
          }else{
            out = true;
            break;
          }
        }
        if(digitalRead(button3)){
          if(pos==0){
            if(time[pos]<24){
              time[pos]++;
            }else{
              time[pos] = 0;
            }
          }else{
            if(time[pos]<60){
              time[pos]++;
            }else{
              time[pos] = 0;
            }
          }
        }
        if(digitalRead(button1)){
          if(pos==0){
            if(time[pos]>0){
              time[pos]--;
            }else{
              time[pos] = 24;
            }
          }else{
            if(time[pos]>0){
              time[pos]--;
            }else{
              time[pos] = 60;
            }
          }
        }
      }
    rtc->set(time[0],time[1],time[2],rtc->getDay(),rtc->getMon(),rtc->getYear());
}
void Controller::alterarData(){
    int date[] = {rtc->getDay(),rtc->getMon(),rtc->getYear()};
    int pos = 0;
    boolean out = false;
    String s = "";
    while(!out){
        delay(100);
        s = String(date[0]);
        s.concat(":");
        s.concat(String(date[1]));
        s.concat(":");
        s.concat(String(date[2]));
        displayLcd->clear();
        displayLcd->setCenterValue("Data:",0,0);
        displayLcd->setCenterValue(s,1,0);
        if(digitalRead(button2)){
          if(pos<3){
            pos++;
          }else{
            out = true;
            break;
          }
        }
        if(digitalRead(button3)){
          if(pos==0){
            if(date[pos]<31){
              date[pos]++;
            }else{
              date[pos] = 1;
            }
          }else if(pos==1){
            if(date[pos]<12){
              date[pos]++;
            }else{
              date[pos] = 1;
            }
          }else{
            if(date[pos]<2050){
              date[pos]++;
            }else{
              date[pos] = 2021;
            }
          }
        }
        if(digitalRead(button1)){
          if(pos==0){
            if(date[pos]>1){
              date[pos]--;
            }else{
              date[pos] = 31;
            }
          }else if(pos==1){
            if(date[pos]>1){
              date[pos]--;
            }else{
              date[pos] = 12;
            }
          }else{
            if(date[pos]>2021){
              date[pos]--;
            }else{
              date[pos] = 2050;
            }
          }
        }
      }
    rtc->set(rtc->getHour(),rtc->getMin(),rtc->getSeg(),date[0],date[1],date[2]);
}

