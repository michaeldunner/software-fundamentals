#include <iostream>

int main() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << " is " << (i % 2 ? "odd" : "even") << std::endl;
    }

    for (int i = 100; i >1; --i) {
        bool prime = true;
        for (int j = 2; j <i; ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            std::cout << i << " is prime" << std::endl;
        }
    }

    // switch statements work with only char and int
    int value = 2;
    switch (value) {
        case 1:
            std::cout << "Value is one" << std::endl;
            break;
        case 2:
            std::cout << "Value is two" << std::endl;
            break;
        case 3:
            std::cout << "Value is three" << std::endl;
            break;
        //like else, default is optional
        default:
            std::cout << "Value is something else" << std::endl;
            break;
    }

    char grade = 'A';
    switch (grade) {
        case 'A':
            std::cout << "Excellent!" << std::endl;
            break;
        case 'B':
            std::cout << "Well done" << std::endl;
            break;
        case 'C':
            std::cout << "You passed" << std::endl;
            break;
        case 'D':
            std::cout << "Better try again" << std::endl;
            break;
        default:
            std::cout << "Invalid grade" << std::endl;
    }

    class Pokemon {
    public:
        enum Type { FIRE, WATER, GRASS };
        Pokemon(Type type, std::string name) : type(type), name(name) {}
        Type getType() const { return type; }
        std::string getName() const { return name; }
    private:
        Type type;
        std::string name;
    };

    Pokemon charmander(Pokemon::FIRE, "Charmander");
    Pokemon squirtle(Pokemon::WATER, "Squirtle");
    Pokemon bulbasaur(Pokemon::GRASS, "Bulbasaur");

    switch (charmander.getType()) {
        case Pokemon::FIRE:
            std::cout << charmander.getName() << " is a Fire type!" << std::endl;
            break;
        case Pokemon::WATER:
            std::cout << charmander.getName() << " is a Water type!" << std::endl;
            break;
        case Pokemon::GRASS:
            std::cout << charmander.getName() << " is a Grass type!" << std::endl;
            break;
    }

    // while loops are very good at doing something until a condition changes
    while (true) {
        break;
    }

    // a while loop with true as its condition will run until broken out of

    // for loops are good for counting or iterating over a known range
    // examples above

    // do while loops will always run at least once
    // whereas a while loop checks condition before running the do while checks after
    do {
        std::cout << "This will run at least once" << std::endl;
    } while (false);

    // int check {10};
    // int check = 10;   // copy initialization (classic)
    // int check(10);   // direct initialization
    // int check{10};   // brace / uniform initialization

    int total = 0;
    int counter = 0;
    while (true) {
        total += counter;
        counter++;
        if (total > 100) {
            std::cout << "Total exceeded 100 at " << counter << " iterations." << std::endl;
            break;
        }
    }
}