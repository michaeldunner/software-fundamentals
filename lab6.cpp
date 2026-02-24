#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

double calculateCharges(double hours);

bool isEven(int number);

double celsius(double fahrenheit);

double fahrenheit(double celsius);

bool perfect(int number);

void printPerfect(int number);

bool flip();

int main() {
    // 1
    double hoursParked1, hoursParked2, hoursParked3;
    std::cout << "Enter the hours parked for 3 cars: ";
    std::cin >> hoursParked1 >> hoursParked2 >> hoursParked3;
    std::cout << "\t" << "Car" << "\t" << "Hours" << "\t" << "Charge"
              << std::endl
              << "\t" << "1" << "\t" << hoursParked1 << "\t"
              << calculateCharges(hoursParked1) << std::endl
              << "\t" << "2" << "\t" << hoursParked2 << "\t"
              << calculateCharges(hoursParked2) << std::endl
              << "\t" << "3" << "\t" << hoursParked3 << "\t"
              << calculateCharges(hoursParked3) << std::endl
              << "\t" << "Total" << "\t"
              << (hoursParked1 + hoursParked2 + hoursParked3) << "\t"
              << (calculateCharges(hoursParked1) +
                  calculateCharges(hoursParked2) +
                  calculateCharges(hoursParked3))
              << std::endl;

    // 2

    // a
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    bool prime = true;
    for (int i = 2; i < number; ++i) {
        if (number % i == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        std::cout << number << " is prime" << std::endl;
    } else {
        std::cout << number << " is not prime" << std::endl;
    }

    // b
    for (int i = 10000; i > 1; --i) {
        bool prime = true;
        for (int j = 2; j < (i / 2); ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            std::cout << i << " is prime" << std::endl;
        }
    }

    // you must check a lot of the numbers because there are a lot of prime
    // numbers between 1 and 10000

    // c
    for (int i = 10000; i > 1; --i) {
        bool prime = true;
        for (int j = 2; j < std::sqrt(i); ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            std::cout << i << " is prime" << std::endl;
        }
    }

    // 3
    while (true) {
        int integer;
        std::cout << "Enter a number (0 to exit): ";
        std::cin >> integer;
        if (integer == 0) {
            break;
        } else {
            if (isEven(integer)) {
                std::cout << integer << " is even" << std::endl;
            } else {
                std::cout << integer << " is odd" << std::endl;
            }
        }
    }

    // 4

    // a
    // function prototypes are declared at the top of the file, and the function
    // definitions are provided after the main function

    // b
    // function prototypes are declared at the top of the file, and the function
    // definitions are provided after the main function

    // c
    std::cout << "\t" << "Celsius to Fahrenheit" << std::endl
              << "Celsius" << "\t" << "Fahrenheit" << std::endl;
    for (int i = 0; i <= 100; ++i) {
        std::cout << i << "\t" << fahrenheit(i) << std::endl;
    }
    std::cout << "\t" << "Fahrenheit to Celsius" << std::endl
              << "Fahrenheit" << "\t" << "Celsius" << std::endl;
    for (int i = 32; i <= 212; ++i) {
        std::cout << i << "\t" << celsius(i) << std::endl;
    }

    // 5
    for (int i = 1; i <= 1000; ++i) {
        if (perfect(i)) {
            std::cout << i << " is perfect. Its factors are: ";
            printPerfect(i);
            std::cout << std::endl;
        }
    }

    // 6
    std::srand(std::time(nullptr));
    int heads = 0;
    for (int i = 1; i <= 100; ++i) {
        if (flip()) {
            heads++;
        }
    }
    std::cout << "Number of heads: " << heads << std::endl;
    std::cout << "Number of tails: " << (100 - heads) << std::endl;
}

double calculateCharges(double hours) {
    double charges = 0.0;
    if (hours <= 3) {
        charges = 2.0;
    } else if (hours > 3 && hours <= 19) {
        charges = 2.0 + (hours - 3) * 0.5;
    } else {
        charges = 10.0;  // Maximum charge for a day
    }
    return charges;
}

bool isEven(int number) {
    return number % 2 == 0;
}

double celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

bool perfect(int number) {
    int sum = 0;
    for (int i = 1; i < number; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

void printPerfect(int number) {
    for (int i = 1; i < number; ++i) {
        if (number % i == 0) {
            std::cout << i << " ";
        }
    }
}

bool flip() {
    if (std::rand() % 2 == 0) {
            std::cout << "Heads" << std::endl;
            return true;
        }
        else {
            std::cout << "Tails" << std::endl;
            return false;
        }
}
