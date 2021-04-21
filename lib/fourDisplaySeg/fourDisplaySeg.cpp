#include "Arduino.h"
#include "fourDisplaySeg.h"

FourDisplaySeg::FourDisplaySeg(byte letrass[8],byte fourSeg[4], byte pp){
    for(int x=0; x<8; x++){
        if(x<4){
            this->fourSeg[x] = fourSeg[x];
            pinMode(this->fourSeg[x],OUTPUT);
        }
        this->letras[x] = letrass[x];
        pinMode(this->letras[x],OUTPUT);
    }
    this->pp = pp;
    pinMode(this->pp,OUTPUT);
    this->setCaracter('o');
    this->setDisplay('o');
    this->delayBetween = 1;

}
void FourDisplaySeg::circular(int timeDelay){
    digitalWrite(this->letras[0],HIGH);
    digitalWrite(this->fourSeg[0],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[0],LOW);
    digitalWrite(this->fourSeg[1],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[1],LOW);
    digitalWrite(this->fourSeg[2],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[2],LOW);
    digitalWrite(this->fourSeg[3],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[0],LOW);
    digitalWrite(this->letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[1],LOW);
    digitalWrite(this->letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[2],LOW);
    digitalWrite(this->letras[3],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[3],LOW);
    digitalWrite(this->fourSeg[2],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[2],LOW);
    digitalWrite(this->fourSeg[1],HIGH);
    delay(timeDelay);
    digitalWrite(this->fourSeg[1],LOW);
    digitalWrite(this->fourSeg[0],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[3],LOW);
    digitalWrite(this->letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[4],LOW);
    digitalWrite(this->letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(this->letras[5],LOW);
}
void FourDisplaySeg::setCaracter(char letra){
    switch(letra){
        case '1':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],LOW);
        break;
        case '2':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],HIGH);
        break;
        case '3':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '4':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '5':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '6':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '7':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],LOW);
            
        break;
        case '8':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '9':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case '0':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],LOW);
            
        break;
        case 'A':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'a':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'B':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'b':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'c':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],LOW);
            
        break;
        case 'C':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],LOW);
            
        break;
        case 'd':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'D':
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],HIGH);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'E':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'e':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],HIGH);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
            
        break;
        case 'F':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
        break;
        case 'f':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
        break;
        case 'P':
            digitalWrite(this->letras[0],HIGH);
            digitalWrite(this->letras[1],HIGH);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],HIGH);
            digitalWrite(this->letras[5],HIGH);
            digitalWrite(this->letras[6],HIGH);
        break;
        case ':':
            digitalWrite(this->pp,HIGH);
        break;
        case '-':
            digitalWrite(this->pp,LOW);
        break;
        default:
            digitalWrite(this->letras[0],LOW);
            digitalWrite(this->letras[1],LOW);
            digitalWrite(this->letras[2],LOW);
            digitalWrite(this->letras[3],LOW);
            digitalWrite(this->letras[4],LOW);
            digitalWrite(this->letras[5],LOW);
            digitalWrite(this->letras[6],LOW);
            digitalWrite(this->letras[7],LOW);
            digitalWrite(this->pp,LOW);
        break;
    }
}
void FourDisplaySeg::setDisplay(char numberDisplay){
   switch (numberDisplay)
    {
    case 0:
        digitalWrite(this->fourSeg[0],HIGH);
        digitalWrite(this->fourSeg[1],LOW);
        digitalWrite(this->fourSeg[2],LOW);
        digitalWrite(this->fourSeg[3],LOW);
    break;
    case 1:
        digitalWrite(this->fourSeg[0],LOW);
        digitalWrite(this->fourSeg[1],HIGH);
        digitalWrite(this->fourSeg[2],LOW);
        digitalWrite(this->fourSeg[3],LOW);
    break;
    case 2:
        digitalWrite(this->fourSeg[0],LOW);
        digitalWrite(this->fourSeg[1],LOW);
        digitalWrite(this->fourSeg[2],HIGH);
        digitalWrite(this->fourSeg[3],LOW);
    break;
    case 3:
        digitalWrite(this->fourSeg[0],LOW);
        digitalWrite(this->fourSeg[1],LOW);
        digitalWrite(this->fourSeg[2],LOW);
        digitalWrite(this->fourSeg[3],HIGH);
    break;
    default:
        digitalWrite(this->fourSeg[0],LOW);
        digitalWrite(this->fourSeg[1],LOW);
        digitalWrite(this->fourSeg[2],LOW);
        digitalWrite(this->fourSeg[3],LOW);
        break;
    }
}
void FourDisplaySeg::setStringOnDisplay(String fourDisplay){
    int currentDisplay = -1;
    for(int x=0; x<fourDisplay.length(); x++){
        if(fourDisplay[x] == '.'){
            digitalWrite(this->letras[7],HIGH);
            this->setDisplay(currentDisplay);
            delay(this->delayBetween);
            digitalWrite(this->letras[7],LOW);
        }else{
            if(fourDisplay[x] == ':' || fourDisplay[x] == '-'){
                this->setCaracter(fourDisplay[x]);
                delay(this->delayBetween);
            }else{
                currentDisplay++;
                this->setCaracter(fourDisplay[x]);
                this->setDisplay(currentDisplay);
                delay(1);
            }
        }
    }
}
void FourDisplaySeg::snake(int timeDelay){
    setDisplay(0);
    digitalWrite(letras[0],HIGH);
    delay(timeDelay);
    digitalWrite(letras[0],LOW);
    digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
    digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
    setDisplay(1);
    digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
    digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
digitalWrite(letras[0],HIGH);
    delay(timeDelay);
    digitalWrite(letras[0],LOW);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
    setDisplay(2);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
digitalWrite(letras[0],HIGH);
    delay(timeDelay);
    digitalWrite(letras[0],LOW);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
    setDisplay(3);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
digitalWrite(letras[0],HIGH);
    delay(timeDelay);
    digitalWrite(letras[0],LOW);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
digitalWrite(letras[3],HIGH);
    delay(timeDelay);
    digitalWrite(letras[3],LOW);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
    setDisplay(2);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
digitalWrite(letras[3],HIGH);
    delay(timeDelay);
    digitalWrite(letras[3],LOW);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
    setDisplay(1);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
digitalWrite(letras[3],HIGH);
    delay(timeDelay);
    digitalWrite(letras[3],LOW);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
    setDisplay(0);
digitalWrite(letras[1],HIGH);
    delay(timeDelay);
    digitalWrite(letras[1],LOW);
digitalWrite(letras[2],HIGH);
    delay(timeDelay);
    digitalWrite(letras[2],LOW);
digitalWrite(letras[3],HIGH);
    delay(timeDelay);
    digitalWrite(letras[3],LOW);
digitalWrite(letras[4],HIGH);
    delay(timeDelay);
    digitalWrite(letras[4],LOW);
digitalWrite(letras[5],HIGH);
    delay(timeDelay);
    digitalWrite(letras[5],LOW);
}