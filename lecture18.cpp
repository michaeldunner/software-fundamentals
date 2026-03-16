#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
    std::shared_ptr<int> ptr2 = ptr1;
    std::weak_ptr<int> ptr3 = ptr1;

    // you can use use_count to check how many shared_ptr are sharing the same
    // object
    
    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;

    // inheritance is used to allow a new class (derived class) to inherit
    // propertires from an exisiting class (base class)

    // i like calling them parent and child classes

    // this is the concept of hierarchy in object oriented programming

    // derived classes can have their own properties and methods in addition to
    // the inherited
    // they can also be the base class for other classes

    // base class

    class Shape {
       public:
        Shape(int x, int y) : positionX(x), positionY(y) {
        }
        void displayPosition() {
            std::cout << "Position: (" << positionX << ", " << positionY << ")"
                      << std::endl;
        }

       private:
        int positionX;
        int positionY;
    };

    // derived class

    class Circle : public Shape {
       public:
        Circle(int x, int y, int r) : Shape(x, y), radius(r) {
        }
        void displayRadius() {
            std::cout << "Radius: " << radius << std::endl;
        }

       private:
        int radius;
    };

    Circle circle(5, 10, 15);
    circle.displayPosition();
    circle.displayRadius();

    // you can also still use the base class if you care

    Shape shape(3, 4);
    shape.displayPosition();
}