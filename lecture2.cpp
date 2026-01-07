#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    double number1 = 3/2;
    std::cout << "3/2 = "<< number1 << std::endl;

    double number2 = 3.0/2.0;
    std::cout << "3.0/2.0 = "<< number2 << std::endl;

    char value = 64;
    std::cout << "The character for ASCII value 64 is: " << value << std::endl;
    std::cout << sizeof(value) << std::endl;

    // imagine an int goes from -5 to 5
    // unsigned int goes from 0 to 10
    unsigned int nume = -1;
    std::cout << "The value of unsigned int nume when assigned -1 is: " << nume << std::endl;
    // this is 2^32 - 1 = 4294967295 on a typical system where unsigned int is 4 bytes


    //byte is 8 bits
    
    return 0;
}
