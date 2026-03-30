#include <iostream>
#include <memory>
#include <string>
#include <vector>

// polymorphism means many forms

// in programming polymorphism is the ability of a single function, method,
// or operator to behave differently based on the object it is acting upon

// polymorphism can be classified into two types: compile-time polymorphism
// and runtime polymorphism

// compile-time polymorphism is achieved through function overloading and
// operator overloading

// runtime polymorphism is achieved when a method in the parent class is
// overridden in the child class, and the method that gets executed is
// determined at runtime

// polymorphism is implemented via virtual functions

// polymorphism works off base class pointer handles and base class
// reference handles but not off name handles, where a handle is a token,
// typically a pointer, that enables the program to access a resource

// we cannot treat a base class object as a derived class object, but we can
// treat a derived class object as a base class object

// an abstract class is a class that doesn't instantiate objects and is
// designed to be inherited by other classes

// a class that does instantiate objects is called a concrete class

// a class is made abstract by declaring at least one of its virtual
// functions as pure

// example Designing a Flower Drawing System where users can select different
// types of flowers to be drawn. The system should allow users to repeatedly
// choose flowers from a menu, store the selections, and display the
// corresponding drawings without polymorphism: Implement the program using
// separate classes for Rose, Tulip, and Sunflower without using inheritance or
// virtual functions. Store the flower objects in a vector and call their
// respective draw() methods explicitly. Ensure proper memory management if
// using dynamic allocation with polymorphism: Create an abstract base class
// Flower with a pure virtual function draw(). Implement three derived classes
// (Rose, Tulip, Sunflower) that override draw(). Store flower objects in a
// vector of base class pointers and use polymorphism to call draw(). Ensure
// proper memory cleanup by deleting dynamically allocated objects.

// doing it without polymorphism

class Rose {
   public:
    Rose(std::string name) : name{name} {
    }
    void draw() {
        std::cout << "Drawing a rose" << std::endl;
    }

   private:
    std::string name;
};

class Tulip {
   public:
    Tulip(std::string name) : name{name} {
    }
    void draw() {
        std::cout << "Drawing a tulip" << std::endl;
    }

   private:
    std::string name;
};

class SunFlower {
   public:
    SunFlower(std::string name) : name{name} {
    }
    void draw() {
        std::cout << "Drawing a sunflower" << std::endl;
    }

   private:
    std::string name;
};

enum FlowerType { ROSE, TULIP, SUNFLOWER };

struct Flower {
    FlowerType type;
    std::shared_ptr<void> flower;
};

int main() {
    std::vector<Flower> flowerObjects;
    int user_choice{0};

    while (true) {
        std::cout << "Enter 1 for Rose, 2 for Tulip, 3 for Sunflower"
                  << std::endl;
        std::cin >> user_choice;

        if (user_choice != 1 && user_choice != 2 && user_choice != 3) {
            break;
        }

        switch (user_choice) {
            case 1:
                flowerObjects.push_back(
                    {ROSE, std::make_shared<Rose>("this is rose")});
                break;
            case 2:
                flowerObjects.push_back(
                    {TULIP, std::make_shared<Tulip>("this is tulip")});
                break;
            case 3:
                flowerObjects.push_back({SUNFLOWER, std::make_shared<SunFlower>(
                                                        "this is sunflower")});
                break;
            default:
                break;
        }
    }

    for (auto flower : flowerObjects) {
        switch (flower.type) {
            case ROSE:
                static_cast<Rose*>(flower.flower.get())->draw();
                break;
            case TULIP:
                static_cast<Tulip*>(flower.flower.get())->draw();
                break;
            case SUNFLOWER:
                static_cast<SunFlower*>(flower.flower.get())->draw();
                break;
            default:
                break;
        }
    }
}

// with polymorphism

// flower to abstract class

class Flower2 {
   public:
    Flower2(std::string name) : name{name} {
    }
    // pure virtual function makes this class abstract
    virtual void draw() const = 0;

   private:
    std::string name;
};

// is a relationship between the two classes

class Rose2 : public Flower2 {
   public:
    Rose2(std::string name) : Flower2{name} {
    }
    void draw() const override {
        std::cout << "Drawing a rose" << std::endl;
    }
    // this line errors because you can't instantiate an abstract class
    // private: Flower2 flower;
};

class Tulip2 : public Flower2 {
   public:
    Tulip2(std::string name) : Flower2{name} {
    }
    void draw() const override {
        std::cout << "Drawing a tulip" << std::endl;
    }
};

class SunFlower2 : public Flower2 {
   public:
    SunFlower2(std::string name) : Flower2{name} {
    }
    void draw() const override {
        std::cout << "Drawing a sunflower" << std::endl;
    }
};

int main2() {
    std::vector<std::shared_ptr<Flower2>> flowerObjects;
    int user_choice{0};

    while (true) {
        std::cout << "Enter 1 for Rose, 2 for Tulip, 3 for Sunflower"
                  << std::endl;
        std::cin >> user_choice;

        if (user_choice != 1 && user_choice != 2 && user_choice != 3) {
            break;
        }

        switch (user_choice) {
            case 1:
                flowerObjects.push_back(
                    std::make_shared<Rose2>("this is rose"));
                break;
            case 2:
                flowerObjects.push_back(
                    std::make_shared<Tulip2>("this is tulip"));
                break;
            case 3:
                flowerObjects.push_back(
                    std::make_shared<SunFlower2>("this is sunflower"));
                break;
            default:
                break;
        }
    }

    for (auto flower : flowerObjects) {
        flower->draw();
    }

    // idk if this was everything
}