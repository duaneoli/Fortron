#ifndef _TIMER_
#define _TIMER_
#include "Arduino.h"

#define SECS_PER_MIN  (60UL)
#define SECS_PER_HOUR (3600UL)
#define SECS_PER_DAY  (SECS_PER_HOUR * 24L)

/* Useful Macros for getting elapsed time */
#define numberOfSeconds(_time_) (_time_ % SECS_PER_MIN)  
#define numberOfMinutes(_time_) ((_time_ / SECS_PER_MIN) % SECS_PER_MIN) 
#define numberOfHours(_time_) (( _time_% SECS_PER_DAY) / SECS_PER_HOUR)

struct DefaultTimer{
    int seconds;
    int minutes;
    int hours;
};

struct Countdown{
    long time;
    unsigned timeRequest;
    unsigned long init;
    int lastSeconds;
};

class TimerRegress {
    private:
    unsigned long t1;
    unsigned long t2;
    String displaySegments;
    DefaultTimer * defaultTimer;
    Countdown * countdown;
    boolean currentFirst;
    boolean stop;
    public:
        TimerRegress();
        void updateTimer(unsigned long t);
        void toStringFourDisplay();
        void setInitTimer();
        void setTimer(unsigned long t);
        void countdownClock();
        boolean isStop();
        int getHours();
        int getMinutes();
        int getSeconds();
        void pause();
        String getString();
};

#endif