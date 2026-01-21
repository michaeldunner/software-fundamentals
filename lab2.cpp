#include <iostream>

int main(){
    // 2.18
    std::cout << "Enter two integers:" << std::endl;
    int num1, num2;
    std::cin >> num1 >> num2;

    if (num1 > num2){
        std::cout << num1 << " is larger." << std::endl;
    }
    else if (num2 > num1){
        std::cout << num2 << " is larger." << std::endl;
    }
    else {
        std::cout << "The numbers are equal." << std::endl;
    }

    // 2.20
    std::cout << "Enter the radius of the circle:" << std::endl;
    double radius;
    std::cin >> radius;
    std::cout << "Diameter: " << 2 * radius << std::endl;
    std::cout << "Circumference: " << 2 * 3.14159 * radius << std::endl;
    std::cout << "Area: " << 3.14159 * radius * radius << std::endl;

    // 2.24
    std::cout << "Enter an integer:" << std::endl;
    int num3;
    std::cin >> num3;
    if (num3 % 2 == 0){
        std::cout << num3 << " is even." << std::endl;
    } else {
        std::cout << num3 << " is odd." << std::endl;
    }

    // 2.29
    // since we haven't learned for loops i will use a class with a print statement in the constructor
    class SquaresAndCubes {
        public:
            SquaresAndCubes(int n){
                std::cout << n << "\t" << n*n << "\t" << n*n*n << std::endl;
            }
    };
    std::cout << "integer\tsquare\tcube" << std::endl;
    SquaresAndCubes(1);
    SquaresAndCubes(2);
    SquaresAndCubes(3);
    SquaresAndCubes(4);
    SquaresAndCubes(5);
    SquaresAndCubes(6);
    SquaresAndCubes(7);
    SquaresAndCubes(8);
    SquaresAndCubes(9);
    SquaresAndCubes(10);

}