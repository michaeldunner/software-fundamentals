#include <iostream>

// a linked list is a linear data structure, where each element, called a
// node, contains data and a pointer to the next node in the sequence

// unlike arrays, linked list nodes are not stored in contiguous memory,
// each node can reside anywhere on the heap

// the heap is a region of memory used for dynamic memory allocation, where
// blocks of memory are allocated and freed in an arbitrary order

// the first node is the head
// the last node points to a null pointer

// linked lists have dynamic size

// the rule of thumb to use a linked list instead of an array is when you
// need to constantly delete and add new eleements, and you don't care about
// random access

// you must make a node class to implement a linked list

struct Node {
    // value of the node
    int data;
    // pointer to next node
    Node* next;
    // constructor to initialize the node and set the next pointer to null
    Node(int value) : data(value), next(nullptr) {
    }
};

// then you make a linked list class

class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() : head(nullptr) {
    }
    ~LinkedList();

    void insertFront(int value);
    void insertBack(int value);
    void deleteNode(int value);
    bool search(int value) const;
    void display() const;
    int size() const;

    // the const keyword after the function declaration indicates that the
    // function does not modify the state of the object, allowing it to be
    // called on const instances of the class
};

void LinkedList::insertFront(int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void LinkedList::insertBack(int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void LinkedList::deleteNode(int val) {
    if (!head) return;
    if (head->data == val) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node* cur = head;
    while (cur->next && cur->next->data != val) cur = cur->next;
    if (cur->next) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
}

bool LinkedList::search(int val) const {
    Node* cur = head;
    while (cur) {
        if (cur->data == val) return true;
        cur = cur->next;
    }
    return false;
}

void LinkedList::display() const {
    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << " -> NULL" << std::endl;
}
int LinkedList::size() const {
    int count = 0;
    for (Node* cur = head; cur; cur = cur->next) count++;
    return count;
}

int main() {
}
