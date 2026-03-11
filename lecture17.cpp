#include <iostream>
#include <memory>

// class for shared_ptr

class MyC1ass {
   public:
    MyC1ass() {
        std::cout << "Constructor invoked" << std::endl;
    }
    ~MyC1ass() {
        std::cout << "Destructor invoked" << std::endl;
    }
};

int main() {
    // you can use the new operator to dynamically allocate memory
    // you can remove the alocated memory with the delete operator

    // an example of a dynamic array is below

    int* dynamicArray = new int[5]{1, 2, 3, 4, 5};

    // not releasing dynamically allocated memory can lead to memory leaks

    delete[] dynamicArray;

    // also add this line to prevent dangling pointer

    dynamicArray = nullptr;

    // allegedly
    // you can use malloc to manage memory in C++

    // don't delete memory not allocated with new

    // a smart pointer is a wrapper over a a pointer with an operator overloaded
    // they are a safe way to manipulate pointers without the risk of memory
    // leaks

    // a unique_ptr is a dynamically allocated object shared by only one object

    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);

    // to delete

    ptr1.reset();

    // to transfer ownership

    std::unique_ptr<int> ptr2 = std::move(ptr1);

    // a shared_ptr is a dynamically allocated object shared by multiple objects
    // class above

    std::shared_ptr<MyC1ass> sharedPtr1 = std::make_shared<MyC1ass>();
    std::cout << "Shared count: " << sharedPtr1.use_count() << std::endl;

    std::shared_ptr<MyC1ass> sharedPtr2 = sharedPtr1;
    std::cout << "Shared count: " << sharedPtr1.use_count() << std::endl;

    std::cout << "Shared count: " << sharedPtr1.use_count() << std::endl;

    // a weak_ptr is a special case for a pointer to use with shared_ptr that
    // provides access to an object owned by one or more shared_ptr

    // empty weak pointer
    std::weak_ptr<int> weakPtr1;

    std::shared_ptr<int> shPtr1 = std::make_shared<int>(25);
    weakPtr1 = shPtr1;
}
