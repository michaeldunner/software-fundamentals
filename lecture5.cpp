#include <iostream>

int main(){

    int a = 2;
    // first one incremments after it prints, second one shows that, third one increments before it prints
    std::cout << a++ << std::endl << a << std::endl << ++a << std::endl;

    // algorithms
    // 3 control structures: sequence, selection, iteration
    // sequence is just executing one statement after another
    // selection is making decisions (if, switch)
    // iteration is repeating a block of code (for, while, do while)
    int grade;
    std::cout << "Enter your grade: ";
    std::cin >> grade;

    if (grade >= 60){
        std::cout << "You passed!" << std::endl;
    } else {
        std::cout << "You failed!" << std::endl;
    }

    // one line if statement
    grade >= 60 ? std::cout << "You passed!" << std::endl : std::cout << "You failed!" << std::endl;

}