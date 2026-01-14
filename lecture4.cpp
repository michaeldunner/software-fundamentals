#include <iostream>
#include "BankAccount.h"

int main(){
    BankAccount bankAccount{"TFSA", 8000.00};

    std::cout << "You have " << bankAccount.getBalance() << " in your " << bankAccount.getName() << " account." << std::endl;


    // constructors are special member function that are automatically called when an object is created
    // constructors can initialize objects and set defualt values and facilitate inheritance
    // just make a method with the same name as the class and no return type
    // pass in any parameters you want to use to initialize the object

    
}