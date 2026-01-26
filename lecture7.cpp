#include <iostream>
#include <cstdlib>

int globalInt = 67;

bool isEven(int number) {
    return number % 2 == 0;
};   

// sees these as 2 different functions because of different types
int square(int number) {
    return number * number;
};

double square(double number) {
    return number * number;
};

int diceRoll() {
    return std::rand() % 6 + 1; // returns a number between 1 and 6
}

// function prototype (declaration)
int add(int a, int b);

void useStaticLocal() {
    static int count = 0; // retains its value between calls
    count++;
    std::cout << "Function called " << count << " times." << std::endl;
}

int main() {
    // 2 types of fucntions, standard library functions and user-defined functions
    // go outside the main function, specifically above
    // type name (parameters) { body }
    for (int i = 1; i <= 10; ++i) {
        int random = std::rand();
        std::cout << random << " is " << (isEven(random) ? "even" : "odd") << std::endl;
    }

    std::cout << square(1.5) << std::endl;
    std::cout << square(4) << std::endl;
    
    int lastRoll = 0;
    for (int i = 1; i <= 10; ++i) {
        int roll = diceRoll();
        std::cout << "Dice roll " << i << ": " << roll << std::endl;
        if (roll == lastRoll) {
            std::cout << "You rolled the same number twice in a row!" << std::endl;
            break;
        }
        lastRoll = roll;
    }

    // scope rules 
    // there is global scope where something is defined outside of any function (outside braces{})
    // there is local scope where something is defined inside a function ({inside braces})
    // there is static local scope where something is defined inside a function with the static keyword
    // static means it retains its value between function calls

    // globalInt is defined outside the main function
    std::cout << add(globalInt, globalInt) << std::endl;

    // static local variables retain their value
    for (int i = 1; i <= 5; ++i) {
        useStaticLocal();
    }

    // a stack is a data structure that follows the Last In First Out (LIFO) principle
    // this means that is a function calls another function, the called function must complete before the calling function can continue
    // this is called pushing (adding) to the stack and popping (removing) from the stack
    // remember recursion
    // stack overflow happens when the stack exceeds its limit
}

int add(int a, int b) {
    return a + b;
}
