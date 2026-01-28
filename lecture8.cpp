#include <iostream>

void squareByReference(int&);

// functions can have default arguements that a value will be used if none is
// provided

int getValueOrDefault(int value = 10) {
    return value;
}

// multiple functions can have the same name and they can be differentiated by
// paramter type

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// can also use templates to create generic functions
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    // pass by value parameters are copies of the original arguments
    // pass by reference parameters are aliases to the original arguments
    // to indicate that a function is passed by reference use &
    // so instead of passing in and returning a value it can access the value
    // directly

    std::cout << getValueOrDefault() << std::endl
              << getValueOrDefault(5) << std::endl;

    // this is best practice to intialize variables
    int number{10};

    double a = 4.1;
    double b = 5.2;
    std::cout << add(a, b) << std::endl;
    int c = 3;
    int d = 4;
    std::cout << add(c, d) << std::endl;
}

void squareByReference(int& number) {
    number *= number;
}