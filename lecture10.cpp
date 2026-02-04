#include <array>
#include <iostream>
#include <vector>

void staticArrayInit();

void autoMaticArrayInit();

void printArray(const std::array<std::array<int, 2>, 3>& a);

double divide(double numerator, double denominator);

int main() {
    // can use arrays to get frequency of values
    std::array<int, 20> studentsResponse = {2, 3, 1, 4, 5, 5, 5, 5, 5, 5,
                                            5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    std::array<int, 5> frequency = {0};
    for (int i = 0; i < studentsResponse.size(); i++) {
        const int rating = studentsResponse[i];
        frequency[(rating - 1)] += 1;
    }
    for (int i = 0; i < frequency.size(); i++) {
        std::cout << "Frequency of " << i + 1 << " is " << frequency[i]
                  << std::endl;
    }

    // static arrays are initialized only once and retain their values

    // automatic arrays are initialized each time the function is called

    // multidimesnional arrays are arrays of arrays, can be used to represent
    // tables or matrices

    // Method 1: Using Array Subscript Notation
    int matrix1[3][2] = {{1, 2}, {3, 4}};  // 3 rows, 2 columns
    std::cout << "matrix1[1][1] = " << matrix1[1][1] << "\n";
    // 3 rows, 2 columns
    std::array<std::array<int, 2>, 3> matrix2 = {8, 6, 5, 7, 1};
    std::cout << "matrix2[1][0] = " << matrix2[1][0] << "\n";

    // try and catch blocks are used to handle exceptions, which are errors that
    // occur during program execution they allow you to gracefully handle errors
    // without crashing the program
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    try {
        if (age >= 18) {
            std::cout << "Access granted - you are old enough." << std::endl;
        } else {
            // when you throw an exception, you can specify a value to be passed
            // to the catch block
            throw(age);
        }
        // if you throw an exception, the program will jump to the catch block
        // and execute the code there
    } catch (int myNum) {
        std::cout << "Access denied - You must be at least 18 years old.\n";
        std::cout << "Age is: " << myNum << std::endl;
    }

    // vectors are like lists in python
    // they have dynamic size
    // you can append and remove elements
    // vectors take a lot of memory
    std::vector<int> myVector{2};
    // use push_back to add elements to the end of the vector (append)
    myVector.push_back(3);

    // can print vectors using range based for loops
    for (int i : myVector) {
        std::cout << i << " ";
    }

    // resize vector to a specific size
    // if the new size is larger, new elements are initialized to 0
    // if the new size is smaller, elements are removed from the end
    myVector.resize(5);

    unsigned size{1};
    unsigned newSize{2};
    int* inBuiltArray = new int[size];
    inBuiltArray[0] = 1;
    int* inBuiltArrayResized = new int[newSize];
    for (int i = 0; i < size; i++) {
        inBuiltArrayResized[i] = inBuiltArray[i];
    }
    inBuiltArray[1] = 2;
}

void staticArrayInit(void) {
    // initializes elements to 0 first time function is called
    static std::array<int, 3> array1;

    std::cout << "\nValues on entering staticArrayInit:\n";

    // output contents of array1
    for (size_t i{0}; i < array1.size(); ++i) {
        std::cout << "array1[" << i << "] = " << array1[i] << " ";
    }

    std::cout << "\nValues on exiting staticArrayInit:\n";

    // modify and output contents of array1
    for (size_t j{0}; j < array1.size(); ++j) {
        std::cout << "array1[" << j << "] = " << (array1[j] += 5) << " ";
    }
}

void autoMaticArrayInit(void) {
    // initializes elements each time function is called
    std::array<int, 3> array2{1, 2, 3};  // automatic local array

    // output contents of array2
    for (size_t i{0}; i < array2.size(); ++i) {
        std::cout << "array2[" << i << "] = " << array2[i] << " ";
    }

    std::cout << "\nValues on exiting automaticArrayInit:\n";

    // modify and output contents of array2
    for (size_t j{0}; j < array2.size(); ++j) {
        std::cout << "array2[" << j << "] = " << (array2[j] += 5) << " ";
    }
}

void printArray(const std::array<std::array<int, 2>, 3>& a) {
    // loop through array's rows
    for (auto const& row : a) {
        // loop through columns of current row
        for (auto const& element : row) {
            std::cout << element << ' ';
        }

        std::cout << std::endl;  // start new line of output
    }
}

double divide(double numerator, double denominator) {
    return numerator / denominator;
}