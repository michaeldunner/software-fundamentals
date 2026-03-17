#include <cstdlib>
#include <ctime>
#include <iostream>

// for 1

void moveTortoise(int* square) {
    int roll = std::rand() % 10 + 1;
    if (roll <= 5) {
        *square += 3;
    } else if (roll <= 7) {
        *square -= 6;
    } else {
        *square += 1;
    }
    if (*square < 1) {
        *square = 1;
    }
}

void moveHare(int* square) {
    int roll = std::rand() % 10 + 1;
    if (roll >= 2 && roll <= 4) {
        *square += 9;
    } else if (roll == 5) {
        *square -= 12;
    } else if (roll <= 8) {
        *square += 1;
    } else {
        *square -= 2;
    }
    if (*square < 1) {
        *square = 1;
    }
}

int main() {
    // 1
    std::srand(std::time(nullptr));
    int tortoiseSquare = 1;
    int hareSquare = 1;
    std::cout << "BANG !!!!!" << std::endl
              << "AND THEY'RE OFF !!!!!" << std::endl;
    while (tortoiseSquare < 70 && hareSquare < 70) {
        moveTortoise(&tortoiseSquare);
        moveHare(&hareSquare);
        if (tortoiseSquare == hareSquare) {
            for (int i = 0; i < tortoiseSquare; i++) {
                std::cout << " ";
            }
            std::cout << "OUCH!!!" << std::endl;
        } else if (tortoiseSquare > hareSquare) {
            for (int i = 0; i < hareSquare; i++) {
                std::cout << " ";
            }
            std::cout << "H";
            for (int i = 0; i < tortoiseSquare - hareSquare; i++) {
                std::cout << " ";
            }
            std::cout << "T" << std::endl;
        } else {
            for (int i = 0; i < tortoiseSquare; i++) {
                std::cout << " ";
            }
            std::cout << "T";
            for (int i = 0; i < hareSquare - tortoiseSquare; i++) {
                std::cout << " ";
            }
            std::cout << "H" << std::endl;
        }
    }
    if (tortoiseSquare >= 70 && hareSquare >= 70) {
        std::cout << "It's a tie." << std::endl;
    } else if (tortoiseSquare >= 70) {
        std::cout << "TORTOISE WINS!!!" << std::endl;
    } else {
        std::cout << "Hare wins. Yuch." << std::endl;
    }

    // 2
    class HugeInteger {
       private:
        int digits[40] = {0};

       public:
        HugeInteger(int numbers[40]) {
            for (int i = 0; i < 40; i++) {
                digits[i] = numbers[i];
            }
        }
        bool isEqualTo(HugeInteger other) {
            for (int i = 0; i < 40; i++) {
                if (digits[i] != other.digits[i]) {
                    return false;
                }
            }
            return true;
        }
        bool isNotEqualTo(HugeInteger other) {
            return !isEqualTo(other);
        }
        bool isGreaterThan(HugeInteger other) {
            for (int i = 0; i < 40; i++) {
                if (digits[i] > other.digits[i]) {
                    return true;
                } else if (digits[i] < other.digits[i]) {
                    return false;
                }
            }
            return false;
        }
        bool isLessThan(HugeInteger other) {
            return !isGreaterThan(other) && !isEqualTo(other);
        }
        bool isZero() {
            for (int i = 0; i < 40; i++) {
                if (digits[i] != 0) {
                    return false;
                }
            }
            return true;
        }
    };
    int array1[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4,
                      5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8,
                      9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int array2[40] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8,
                      7, 6, 5, 4, 3, 2, 0, 9, 8, 7, 6, 5, 4,
                      3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    HugeInteger int1(array1);
    HugeInteger int2(array2);
    std::cout << "int1 is equal to int2: " << int1.isEqualTo(int2) << std::endl;
    std::cout << "int1 is not equal to int2: " << int1.isNotEqualTo(int2)
              << std::endl;
    std::cout << "int1 is greater than int2: " << int1.isGreaterThan(int2)
              << std::endl;
    std::cout << "int1 is less than int2: " << int1.isLessThan(int2)
              << std::endl;
    std::cout << "int1 is zero: " << int1.isZero() << std::endl;

    // 3
    class TicTacToe {
       private:
        int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

       public:
        void displayBoard() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        void makeMove(int player) {
            int row, col;
            std::cout << "Player " << player
                      << ", enter your move (row and column): ";
            std::cin >> row >> col;
            if (board[row - 1][col - 1] == 0 && row - 1 >= 0 && row - 1 < 3 &&
                col - 1 >= 0 && col - 1 < 3) {
                board[row - 1][col - 1] = player;
            } else {
                std::cout << "Invalid move. Try again." << std::endl;
                makeMove(player);
            }
        }
        int checkWin() {
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
                    board[i][0] != 0) {
                    return board[i][0];
                }
                if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
                    board[0][i] != 0) {
                    return board[0][i];
                }
            }
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
                board[0][0] != 0) {
                return board[0][0];
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
                board[0][2] != 0) {
                return board[0][2];
            }
            return 0;
        }
        int checkTie() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        return false;
                    }
                }
            }
            return true;
        }
    };
    TicTacToe game;
    int currentPlayer = 1;
    while (true) {
        game.displayBoard();
        game.makeMove(currentPlayer);
        if (game.checkWin() != 0) {
            game.displayBoard();
            std::cout << "Player " << game.checkWin() << " wins!" << std::endl;
            break;
        } else if (game.checkTie()) {
            game.displayBoard();
            std::cout << "The game is a tie!" << std::endl;
            break;
        }
        currentPlayer = (currentPlayer) % 2 + 1;
    }

    // 4
    class Rectangle {
       private:
        double length = 1.0;
        double width = 1.0;

       public:
        double calculatePerimeter() {
            return 2 * (length + width);
        }
        double calculateArea() {
            return length * width;
        }
        double getLength() {
            return length;
        }
        double getWidth() {
            return width;
        }
        void setLength(double newLength) {
            if (newLength > 0.0 && newLength < 20.0) {
                length = newLength;
            } else {
                std::cout
                    << "Invalid length. Length must be between 0.0 and 20.0."
                    << std::endl;
            }
        }
        void setWidth(double newWidth) {
            if (newWidth > 0.0 && newWidth < 20.0) {
                width = newWidth;
            } else {
                std::cout
                    << "Invalid width. Width must be between 0.0 and 20.0."
                    << std::endl;
            }
        }
    };
    Rectangle rect;
    std::cout << "Initial length: " << rect.getLength() << std::endl
              << "Initial width: " << rect.getWidth() << std::endl
              << "Initial perimeter: " << rect.calculatePerimeter() << std::endl
              << "Initial area: " << rect.calculateArea() << std::endl;
    rect.setLength(5.0);
    rect.setWidth(23.0);
    std::cout << "Updated length: " << rect.getLength() << std::endl
              << "Updated width: " << rect.getWidth() << std::endl
              << "Updated perimeter: " << rect.calculatePerimeter() << std::endl
              << "Updated area: " << rect.calculateArea() << std::endl;

    // 5
    class Complex {
       private:
        double real;
        double imaginary;

       public:
        Complex(double r = 1, double i = 1) {
            real = r;
            imaginary = i;
        }

        // a
        Complex operator+(Complex other) {
            return Complex(real + other.real, imaginary + other.imaginary);
        }

        // b
        Complex operator-(Complex other) {
            return Complex(real - other.real, imaginary - other.imaginary);
        }

        // c
        void print() {
            std::cout << "(" << real << ", " << imaginary << ")" << std::endl;
        }
    };
    Complex complex1(2, 3);
    Complex complex2{};
    Complex complex3(4, 5);
    std::cout << "Complex 1: ";
    complex1.print();
    std::cout << "Complex 2: ";
    complex2.print();
    std::cout << "Complex 3: ";
    complex3.print();
    Complex sum = complex1 + complex3;
    std::cout << "Sum of complex1 and complex3: ";
    sum.print();
    Complex difference = complex1 - complex2;
    std::cout << "Difference of complex1 and complex2: ";
    difference.print();
}