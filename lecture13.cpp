#include <iostream>
#include "Circle.h"
#include "Shape.h"
#include "Time.h"

//signature
Time::Time() : hour(0), minute(0), second(0) {
}

void Time::setTime(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}

void Time::printStandardTime() const {
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}

void Time::printUniversalTime() const {
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}

int main() {
    // you can define objects using structs instead of classes
    // everything in a struct is public by default
    struct Point {
        int x;
        int y;

        void print() {
            std::cout << "Point(" << x << ", " << y << ")" << std::endl;
        }
    };

    Point p;
    p.x = 10;
    p.y = 20;
    p.print();

    // sometimes classes from header files are imported twice and cause errors,
    // to prevent this we can use include guards these don't chan ge the
    // origional file but the header's need #ifndef and #define at the beginning
    // and #endif at the bottom

    Time t;
    t.setTime(12, 30, 45);
    t.printStandardTime();
    t.printUniversalTime();

}
