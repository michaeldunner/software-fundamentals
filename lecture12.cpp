#include <iostream>

void passByValue(int value) {
    value = value * value;
}

// javadoc style comment
// goated
/**
 * @brief Squares the given integer
 *
 * @param value The integer to be squared
 */
void passByReference(int& value) {
    value = value * value;
}

void passByPointer(int* value) {
    *value = (*value) * (*value);
}

void updateArray(int a[]) {
    a[1] = 100;
}

int main() {
    int value{10};
    std::cout << "Initial value: " << value << std::endl;
    passByValue(value);
    std::cout << "After pass by value: " << value << std::endl;
    // pass by value does not modify the original variable, it creates a copy of
    // the variable and modifies the copy, while pass by reference modifies the
    // original variable directly
    passByReference(value);
    std::cout << "After pass by reference: " << value << std::endl;
    // pass by reference modifies the original variable directly, it does not
    // create a copy of the variable, it allows the function to modify the
    // original variable through its reference
    passByPointer(&value);
    std::cout << "After pass by pointer: " << value << std::endl;
    // pass by pointer modifies the original variable through its pointer

    // inbuilt arrays are passed by pointer
    int n[3] = {10, 20, 30};
    for (int i : n) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    updateArray(n);
    for (int i : n) {
        std::cout << i << " ";
    }

    // there are four ways to pass a pointer to a function
    // a nonconstant pointer to nonconstant data
    // void function(type* pointerToNonconstantData);
    // a nonconstant pointer to constant data
    // void function(const type* pointerToConstantData);
    // a constant pointer to nonconstant data
    // void function(type* const constantPointerToNonconstantData{&value});
    // a nonconstant pointer to constant data
    // void function(const type* pointerToConstantData{&value});

    // each level provides a different use case

    // sizeof determines the size of a type in bytes

    // you can add or subtract from pointers

    // a pointer can be assigned to another pointer of the same type, but not to
    // a pointer of a different type and not void* (generic pointer) without a
    // cast

    // a void* pointer cannot be dereferenced
    // there is no bounds checking on pointer arithmetic, so it is the
    // programmer's responsibility to ensure that the pointer is pointing to a
    // valid memory location before dereferencing it

    
}
