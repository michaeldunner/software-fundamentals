#include <iostream>

int main() {
    // can add class objects to each other and do other operations too
    // must specify how the operator works for the class objects, this is called
    // operator overloading

    // example
    // Accoutn operator+ (Account& account1, Account& account2) {
    //     Account result;
    //     int total = account1.getBalance() + account2.getBalance();
    //     result.setBalance(total);
    //     return result;
    // }

    // this is binary operator overloading, we can also do unary operator
    // overloading

    // unary overloading has the operator in the class
    // in this case it would take only the second account and add it to the
    // first account

    // the multiplication operator has the same symbol as a pointer

    // the assignment (=) operator and the address (&) operator cannot be
    // overloaded as well as some pointer stuff like . .* :: ?:

    // cannot change arity (the number of operands) of an operator, so cannot
    // make a binary operator into a unary operator or vice versa

    // you cannot make the + operator subtract values unless it is a user
    // defined type but why would you want to

    // the >> and << operators can be overloaded by ... we ended
}
