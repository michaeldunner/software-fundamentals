// need these at beginning for an include guard
#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Circle
{
    void print() {
        std::cout << "This is a circle" << std::endl;
    }
};

// and this at the end
#endif