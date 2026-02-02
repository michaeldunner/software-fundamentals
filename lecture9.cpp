#include <array>
#include <iostream>

// this function uses recursion to calculate the factorial of a number
unsigned long factorial(int number) {
    // base case
    // if there isn't a base case, the function will call itself indefinitely
    if (number == 0) {
        return 1;
        // not base case so keep calling the function
    } else {
        return number * factorial(number - 1);
    }
}

int fibonacci(int n) {
    // two base cases
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    std::cout << factorial(9) << std::endl << std::endl;

    // arrays are a group of variables of the same type
    // type name[size] = {item, item, item,...};
    // very useful for stroring related data
    // arrays in the lower index (like 0) are faster to access
    int fib_sequence[10];
    for (int i = 0; i < 10; i++) {
        fib_sequence[i] = fibonacci(i);
    }
    std::cout << "Fibonacci sequence: ";
    // can't print arrays directly, need to loop through them
    for (int i = 0; i < 10; i++) {
        std::cout << fib_sequence[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int score1 = 10;
    int score2 = 20;
    int score3 = 40;

    int scores[3] = {10, 20, 40};

    // & prints the memory address of a variable
    std::cout << "score 1 is located in " << &score1 << std::endl;
    std::cout << "score 2 is located in " << &score2 << std::endl;
    std::cout << "score 3 is located in " << &score3 << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "score " << i << " is located in " << &scores[i]
                  << std::endl;
    }

    // there is also an array from a class templated
    // std::array
    // it has member functions size(), at(), begin(), end(), etc.
    // at() does bounds checking
    // memory management is automated
    // copyable and assignable
    // overall seem better than regular arrays
    // define using std::array<type, size> name;
    std::array<int, 3> testArray{10, 20, 30};
    std::cout << "testArray has size " << testArray.size() << std::endl;
    std::array<int, 3> testArrayCopy = {};
    testArrayCopy = testArray;

    // vectors are dynamic arrays with resizable size like I used for RREF

    // if you create an array with 10 items and only use 3, the other 7 still take up space
    // they are 0 by default

    // sum elements in an array
    int sum = 0;
    for (int i = 0; i < testArray.size(); i++) {
        sum += testArray.at(i);
    }
    std::cout << "sum of testArray is " << sum << std::endl;
}
