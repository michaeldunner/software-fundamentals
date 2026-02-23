#include <iostream>

// contract
class Time {
   public:
    Time();
    void setTime(int, int, int);
    void printUniversalTime() const;
    void printStandardTime() const;

   private:
    int second;
    int minute;
    int hour;
};