#ifndef _CHESS_
#define _CHESS_
#include "timer.h"
#include "Arduino.h"

struct Player{
    TimerRegress* timer;
    uint8_t button;
};

class ChessClock{
    private:
    Player* player1 = new Player();
    Player* player2 = new Player();
    boolean isPlayer1;
    public:
    ChessClock(uint8_t buttonPlayer1, uint8_t buttonPlayer2);
    void setTime(unsigned long t);
    void setInitPlayer1();
    void setInitPlayer2();
    void exec(boolean *p,boolean *stop);
    String getCurrentTime();
};

#endif