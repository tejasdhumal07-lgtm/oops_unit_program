// Concept 14: Object Slicing Demonstration
// Aim: To understand object slicing and avoid it using references.

// Include input/output stream library
#include <iostream>

// Base class providing a virtual display method
class Base {
public:
    // Virtual function display()
    virtual void display() const {
        // Output identifying Base object
        std::cout << "Base object\n";
    }

    // Default virtual destructor for base class
    virtual ~Base() = default;
};

// Derived class overriding display method
class Derived : public Base {
public:
    // Override display() method
    void display() const override {
        // Output identifying Derived object
        std::cout << "Derived object\n";
    }
};

// Pass-by-value function causing object slicing (Derived part is sliced off)
void displayByValue(Base object) {
    // Calls Base::display because object was copied into a Base instance
    object.display();
}

// Pass-by-reference function preventing object slicing and preserving polymorphism
void displayByReference(const Base& object) {
    // Polymorphically calls Derived::display via reference dispatch
    object.display();
}

// Entry point of program
int main() {
    // Create an instance of Derived class
    Derived derived;

    // Output heading for value pass test
    std::cout << "Passing by value: ";
    // Pass derived by value; triggers object slicing
    displayByValue(derived);

    // Output heading for reference pass test
    std::cout << "Passing by reference: ";
    // Pass derived by reference; preserves polymorphic behavior
    displayByReference(derived);

    // Return status 0
    return 0;
}
