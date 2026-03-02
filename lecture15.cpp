#include <iostream>

// friend class example
class Count {
    friend void setX(Count&, int);

   public:
    Count(int val) : x(val) {
    }

    void print() {
        std::cout << "The value of x is: " << x << std::endl;
    }

   private:
    int x;
};

// this is the friend function that can access the private member x of the Count
// class
void setX(Count& c, int val) {
    // c is object of the Count class and val is the value we want to set x to
    c.x = val;
}

int main() {
    // today we did stuff in a class i don't have so i couldn't follow along

    // objects as members of classes will have their defualt constructor called
    // if it is not explicitly called in the constructor of the class

    // friend functions are functions that are not members of a class but have
    // access to the private and protected members of the class. They are
    // declared with the friend keyword in the class definition.

    // for a class to be a friend of another class, it must be declared as a
    // friend in the class definition of the class it is a friend of

    Count c{10};
    c.print();
    setX(c, 20);
    c.print();

    // you can use the pointer this to access the members of the class from
    // within the class
}