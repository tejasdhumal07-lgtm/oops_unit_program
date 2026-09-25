// Concept 13: Virtual Destructor
// Aim: To demonstrate correct destruction of a derived object through a base pointer.

// Include stream I/O header
#include <iostream>

// Base class with virtual destructor
class Base {
public:
    // Virtual destructor definition
    virtual ~Base() {
        // Output text when Base destructor runs
        std::cout << "Base destructor\n";
    }
};

// Derived class inheriting from Base
class Derived : public Base {
public:
    // Override destructor definition for cleanup
    ~Derived() override {
        // Output text when Derived destructor runs
        std::cout << "Derived destructor\n";
    }
};

// Application entry point
int main() {
    // Dynamically allocate a Derived object and assign its address to a Base pointer
    Base* pointer = new Derived();

    // Deleting via Base pointer correctly triggers Derived destructor first, then Base destructor
    delete pointer;

    // Return 0 for success
    return 0;
}
