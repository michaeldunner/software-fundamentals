#include <iostream>

// int main() {
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

// the >> and << operators can be overloaded
// you would do this to make it easier to print out the class objects
// like formatting the output of a value to go with it's name

// you can make friend operator overloads, this allows you to access private
// members of the class in the operator overload function

// overloeading ++ and -- can be done
// there is some weird stuff with them i don't get it
// you can overload it as a member function or a non member function
// example below
// }

class Date {
    // friend operator overload function can access private members of the class
    friend std::ostream& operator<<(std::ostream&, const Date&);

   public:
    Date(int m = 1, int d = 1, int y = 1900);  // default constructor
    void setDate(int, int, int);               // set month, day, year
    Date& operator++();                        // prefix increment operator
    Date operator++(int);                      // postfix increment operator
    Date& operator+=(unsigned int);            // add days, modify object
    static bool leapYear(int);                 // is date in a leap year?
    bool endOfMonth(int) const;                // is date at the end of month?
    // prefix is ++date, postfix is date++
   private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    static const std::array<unsigned int, 13> days;  // days per month
    void helpIncrement();  // utility function for incrementing date
};

int main() {
    // example of useage of date class and its operator overloads
    Date d1(12, 27, 2010);  // December 27, 2010
    Date d2;                // defaults to January 1, 1900
    std::cout << "d1 is " << d1 << "\n d2 is " << d2;
    std::cout << "\n\n d1 += 7 is " << (d1 += 7);
    d2.setDate(2, 28, 2008);
    std::cout << "\n\n d2 is " << d2;
    std::cout << "\n ++d2 is " << ++d2 << " (leap year allows 29th)";
    Date d3(7, 13, 2010);
    std::cout << "\n\n Testing the prefix increment operator:\n"
              << " d3 is " << d3 << std::endl;
    std::cout << "++d3 is " << ++d3 << std::endl;
    std::cout << " d3 is " << d3;
    std::cout << "\n\n Testing the postfix increment operator:\n"
              << " d3 is " << d3 << std::endl;
    std::cout << "d3++ is " << d3++ << std::endl;
    std::cout << " d3 is " << d3 << std::endl;
}
