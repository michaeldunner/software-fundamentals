#include <iostream>

int main() {
    // destructors are not inherited by derived classes

    // multiple choice question
    // assuming the definition,
    // class BasePlusCommissionEmployee : public CommissionEmployee
    // which of the following is false?

    // CommissionEmployee is the base class and BasePlusCommissionEmployee is
    // the derived class

    // the keyword public indicates the type of inheritance

    // the colon (:) in the header of the class definition indicates inheritance

    // all the public and protected members of class BasePlusCommissionEmployee
    // are inherited as public and protected members, respectively, into class
    // CommissionEmployee

    // answer
    // all the public and protected members of class BasePlusCommissionEmployee
    // are inherited as public and protected members, respectively, into class
    // CommissionEmployee
    // because all the public and protected members of class CommissionEmployee
    // are inherited as public and protected members, respectively, into class
    // BasePlusCommissionEmployee

    // multiple choice question
    // which of the following statements about inheriting base class
    // constructors is false

    // by default each inherited constructor has the same access level (public,
    // protected, or private) as its correseponding base class constructor

    // when an object of derived class is created, first the derived class
    // constrcutors are executed

    // when a derived-class object is destroyed, the program calls that object’s
    // base destructor

    // if the derived class does not explicitly define constructors, the
    // compiler generates a default

    // answer
    // when an object of derived class is created, first the derived class
    // constrcutors are executed
    // because when an object of derived class is created, first the base class
    // constrcutors are executed, then the derived class constrcutors are
    // executed

    // multiple choice question
    // when an object of a derived class is instantiated, the ________
    // constructor initializes the ________ members

    // base class, derived class

    // derived class, base class

    // derived class, public

    // base class, base class

    // answer
    // base class, base class
    // because when an object of a derived class is instantiated, the base class
    // constructor initializes the base class members, then the derived class
    // constructor initializes the derived class members

    // instead of inheritance you can use composition

    // composition is a design principle in which a class is composed of one or
    // more objects of other classes in order to achieve code reuse and
    // flexibility
    // which is useful because parent and child classes are more rigidly
    // structured than composition
}
