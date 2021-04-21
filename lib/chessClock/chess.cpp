#include "Arduino.h"
#include "chess.h"


ChessClock::ChessClock(uint8_t buttonPlayer1, uint8_t buttonPlayer2){
    this->player1->timer = new TimerRegress();
    this->player2->timer = new TimerRegress();
    this->player1->button = buttonPlayer1;
    this->player2->button = buttonPlayer2;
    this->isPlayer1 = true;
}
void ChessClock::setTime(unsigned long t){
    this->player1->timer->setTimer(t);
    this->player2->timer->setTimer(t);
}
void ChessClock::setInitPlayer1(){
    this->player1->timer->setInitTimer();
}
void ChessClock::setInitPlayer2(){
    this->player2->timer->setInitTimer();
}
String ChessClock::getCurrentTime(){
    if(isPlayer1){
        return this->player1->timer->getString();
    }else{
        return this->player2->timer->getString();
    }
}
void ChessClock::exec(boolean *p,boolean *stop){
    *p = isPlayer1;
    if(isPlayer1){
        this->player1->timer->countdownClock();
        if(this->player1->timer->isStop()){
            *stop = true;
        }else{
            if(digitalRead(this->player1->button)){
                isPlayer1 = false;
                this->player1->timer->pause();
                this->setInitPlayer2();
            }
        }
    }else{
        this->player2->timer->countdownClock();
        if(this->player2->timer->isStop()){
            *stop = true;
        }else{
            if(digitalRead(this->player2->button)){
                isPlayer1 = true;
                this->player2->timer->pause();
                this->setInitPlayer1();
            }
        }
    }
}



