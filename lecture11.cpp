#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int main() {
    // we can use the built in binary_search function to search for an element
    // an array sorting the array is a prerequisite for using binary search it
    // is also very important to sort data efficiently
    // it can significantly improve the performance of search algorithms

    std::array<std::string, 3> colours{"red", "green", "blue"};
    for (std::string colour : colours) {
        std::cout << colour << " ";
    }
    std::cout << std::endl;

    // sort with
    // std::sort(arr.begin(), arr.end()) sorts the array in ascending order

    std::sort(colours.begin(), colours.end());
    for (std::string colour : colours) {
        std::cout << colour << " ";
    }
    std::cout << std::endl;

    // then search with
    // std::binary_search(arr.begin(), arr.end(), value) returns true if value
    // is found in the
    std::cout << (std::binary_search(colours.begin(), colours.end(), "red")
                      ? "Found"
                      : "Not Found")
              << std::endl;
    std::cout << (std::binary_search(colours.begin(), colours.end(), "yellow")
                      ? "Found"
                      : "Not Found")
              << std::endl;

    // inbuilt arrays can also be sorted using std::sort but we need to provide
    // pointers to the first and one past the last element of the array
    int inBuiltArray[3] = {10, 30, 20};
    std::sort(&inBuiltArray[0], &inBuiltArray[3]);
    std::cout << "For inbuilt Array" << std::endl;
    for (int a : inBuiltArray) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    // this prints the location of the max element
    auto maxElement = std::max_element(colours.begin(), colours.end());
    std::cout << "Max element: " << *maxElement << std::endl;

    // a pointer contains the memory address of a variable that contains a
    // specific value
    // a variable name directly references the value, and a pointer indirectly
    // references the value through its memory address (called indirection)
    int *countPtr, count;
    // count is an int, not a pointer to the int
    // the * operator is used to declare a pointer and only applies to the
    // variable name immediately following it

    int a = 10;
    int& b = a;
    b = 20;
    int* p = &a;

    std::cout << &b << std::endl
              << &a << std::endl
              << a << std::endl
              << b << std::endl
              << p << std::endl
              << *p << std::endl;

    // the difference between * and & is that * is the dereference operator, it
    // returns the value at the memory address stored in a pointer, while & is
    // the address-of operator, it returns the memory address of a variable

    // a nullptr (null pointer) is a pointer that does not point to any valid
    // memory location
    // & is the address-of operator, it returns the memory address of a variable
    std::string* stringPtr = nullptr;

    // can pass arguments to a function by using reference arguments and pointer
    // arguments (as well as values which we knew)

    // for arguments
    // void function(type& referenceArg);

    // for pointers
    // void function(type* pointerArg);

    // to summarize
    // references (&) are alias for existing variables
    // int a = 10;
    // reference to a
    // int& ref = a;
    // modify a
    // ref = 20;
    // pointers (*) are variables that store memory addresses
    // int b = 30;
    // pointer to b
    // int* ptr = &b;
    // modify b
    // *ptr = 40;
}
