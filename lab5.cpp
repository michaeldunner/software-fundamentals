#include <iostream>

int main() {
    // 1
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < rows - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i; j++) {
            std::cout << i - j;
        }
        for (int j = 1; j < i; j++) {
            std::cout << j + 1;
        }
        std::cout << std::endl;
    }

    // 2
    int previousOne;
    int previousTwo;
    for (int i = 0; i < 15; i++) {
        if (i == 0) {
            std::cout << 0 << " ";
            previousTwo = 0;
        } else if (i == 1) {
            std::cout << 1 << " ";
            previousOne = 1;
        } else {
            int current = previousOne + previousTwo;
            std::cout << current << " ";
            previousTwo = previousOne;
            previousOne = current;
        }
    }
    std::cout << std::endl;

    // 3
    int years = 2023 - 1626;
    for (int i = 5; i <= 10; i++) {
        double value = 24.0;
        double interestRate = 1.0 + i / 100.0;
        for (int j = 0; j < years; j++) {
            value *= interestRate;
        }
        std::cout << "At " << i << "% interest, the value becomes $" << value << std::endl;
    }   
}
