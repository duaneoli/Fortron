#ifndef DS1307_h
#define DS1307_h

//#define daysOfTheWeek[7][12] {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#include <inttypes.h>
struct fullTime{
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
};

struct fullDate{
  uint8_t dayName;
  uint8_t day;
  uint8_t month;
  uint16_t year; 
};

class DS1307
{
  public:
    DS1307();
    void begin(void);
    void start(void);
    void stop(void);
    void set(uint8_t hour,uint8_t min,uint8_t sec, uint8_t day, uint8_t month, uint16_t year);
    void set( int hour, int min,int sec, int day, int month, int year);
    void update();
    int getHour();
    int getMin();
    int getSeg();
    int getDay();
    int getMon();
    int getYear();
    String getFullTime();
    String getFullDate ();

  private:
    uint8_t bin2bcd(uint8_t val);
    uint8_t bcd2bin(uint8_t val);
    fullTime* fulltime;
    fullDate* fulldate;
};


#endif //DS1307_h
