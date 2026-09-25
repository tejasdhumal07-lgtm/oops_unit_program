// Concept 8: Base Pointer Without Virtual Function
// Aim: To observe static binding when a base function is not virtual.

// Include stream I/O library
#include <iostream>

// Base class definition with a non-virtual member function
class Base {
public:
    // Non-virtual display function in Base
    void display() const {
        // Output text indicating Base display function execution
        std::cout << "Base display function\n";
    }
};

// Derived class inheriting publicly from Base
class Derived : public Base {
public:
    // Non-virtual display function redefining (hiding) Base::display
    void display() const {
        // Output text indicating Derived display function execution
        std::cout << "Derived display function\n";
    }
};

// Application entry point
int main() {
    // Instantiate object of Derived class
    Derived derivedObject;

    // Create Base pointer pointing to the address of derivedObject
    Base* basePointer = &derivedObject;

    // Call display() via basePointer; static binding calls Base::display() because display is non-virtual
    basePointer->display();

    // Return 0 for success
    return 0;
}
