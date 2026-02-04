#include <iostream>
#include <iomanip>

unsigned long factorial(int palindromeNumber);

int main() {
    // 1
    int palindromeNumber;
    std::cout << "Enter an 5 digit integer: ";
    std::cin >> palindromeNumber;
    int firstDigit = palindromeNumber % 10;
    int lastDigit = (palindromeNumber - (palindromeNumber % 10)) / 10000;
    if (firstDigit != lastDigit) {
        std::cout << "The number is not a palindrome." << std::endl;
    } else {
        int secondDigit = (palindromeNumber / 10) % 10;
        int fourthDigit = (palindromeNumber / 1000) % 10;
        if (secondDigit != fourthDigit) {
            std::cout << "The number is not a palindrome." << std::endl;
        } else {
            std::cout << "The number is a palindrome." << std::endl;
        }
    }

    // 2
    int side1, side2, side3;
    std::cout << "Enter the lengths of the three sides of a triangle: ";
    std::cin >> side1 >> side2 >> side3;
    if ((side1 + side2) > side3 &&
        (side1 + side3) > side2 &&
        (side2 + side3) > side1) {
        std::cout << "The lengths can form a triangle." << std::endl;
    } else {
        std::cout << "The lengths cannot form a triangle." << std::endl;
    }

    // 3
    int factorialNumber;
    std::cout << "Enter a non-negative integer to compute its factorial: ";
    std::cin >> factorialNumber;
    if (factorialNumber < 0) {
        std::cout << "Factorial is not defined for negative integers." << std::endl;
    } else {
        unsigned long result = factorial(factorialNumber);
        std::cout << "Factorial of " << factorialNumber << " is " << result << std::endl;
    }

    // 4
    double e = 0.0;
    for (int i = 0; i < 11; i++) {
        e += 1.0 / factorial(i);
    }
    std::cout << std::fixed << std::setprecision(11) << "The value of e is " << e << std::endl;

    // 5
    double grossSales = 0;
    while (grossSales >= 0) {
        std::cout << "Enter the gross sales amount or a negative number to quit: ";
        std::cin >> grossSales;
        if (grossSales >= 0) {
            std::cout << "You earned $" << 200 + 0.09 * grossSales << std::endl;
        }
    }

    // 6
    int counter = 0;
    double number, largest;
    while (counter < 10) {
        std::cout << "Enter a number: ";
        std::cin >> number;
        if (counter == 0) {
            largest = number;
        } else {
            if (number > largest) {
                largest = number;
            }
        }
        counter++;
    }
    std::cout << "The largest number is " << largest << std::endl;
}

unsigned long factorial(int number) {
    if (number == 0) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}