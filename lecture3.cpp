#include <iostream>
#include <string>

// function returnType name (Paramters)

int add(int a, int b) {
    return a + b;
}

double divide(double a, double b) {
    return a / b;
}

// classes are combinations of data and functions
// they can be private protected (safe within its own function within the class)or public
// class ClassName {
//    accessSpecifier:
//        data members
//        member functions
// };
class Area{
    public:
        double calculateArea(){
            return length * width;
        }
    public:
        double length;
        double width;
};

class BankAccount{
    private:
        std::string name;

    public:
        std::string getName(){
            return name;
        }
        void setName(std::string name){
            this->name = name;
        }
};

// int main is a function too but its the primary function
int main() {
    std::cout << add(4, 5) << std::endl;
    std::cout << divide(5.0, 2.0) << std::endl;

    Area rect;
    rect.length = 5.0;
    rect.width = 3.0;
    std::cout << "Area of rectangle: " << rect.calculateArea();

    BankAccount account;
    std::string name;
    std::cout << "\nEnter account name: ";
    std::getline(std::cin, name);
    account.setName(name);
    std::cout << "\nAccount Name: " << account.getName() << std::endl;
}

// he showed how to move class to different file but i wasn't locked in
// use std::getLine to get line cin stops aftyer space