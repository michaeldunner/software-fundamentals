#include <iostream>

void printAsterisk();
void printBlank();
void printNewLine();

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
        std::cout << "At " << i << "% interest, the value becomes $" << value
                  << std::endl;
    }

    // 4
    // checks each hypotenuse
    for (int hypotenuse = 1; hypotenuse <= 500; hypotenuse++) {
        // checks each side1
        for (int side1 = 1; side1 < hypotenuse; side1++) {
            for (int side2 = 1; side2 < hypotenuse; side2++) {
                if (side1 * side1 + side2 * side2 == hypotenuse * hypotenuse) {
                    std::cout << "Pythagorean triple: " << side1 << ", "
                              << side2 << ", " << hypotenuse << std::endl;
                    // don't need to check more side2 for this hypotenuse and
                    // side1
                    break;
                }
            }
        }
    }

    // 5
    int totalRows = 9;
    for (int row = 1; row <= totalRows; row++) {
        if (row > totalRows / 2 + 1) {
            for (int col = 1; col <= totalRows / 2 + row - totalRows; col++) {
                printBlank();
            }
            for (int col = 1; col <= 2 * (totalRows - row) + 1; col++) {
                printAsterisk();
            }
        } else {
            for (int col = 1; col <= totalRows / 2 + 1 - row; col++) {
                printBlank();
            }
            for (int col = 1; col <= 2 * row - 1; col++) {
                printAsterisk();
            }
        }
        printNewLine();
    }

    // 6
    double pi = 0.0;
    for (int terms = 0; terms < 1000; terms++) {
        
            pi += (4.0 / (2 * terms + 1)) * (terms % 2 == 0 ? 1 : -1);
        std::cout << "Term " << terms + 1 << " " << pi << std::endl;
    }
}

void printAsterisk() {
    std::cout << "*";
}

void printBlank() {
    std::cout << " ";
}

void printNewLine() {
    std::cout << std::endl;
}
