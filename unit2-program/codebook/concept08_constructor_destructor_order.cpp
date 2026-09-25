// Header file for stream IO operations
#include <iostream>

// Base class definition
class Base {
public:
    // Base class default constructor
    Base() {
        // Log construction of Base class
        std::cout << "Base constructor\n";
    }
    // Base class destructor
    ~Base() {
        // Log destruction of Base class
        std::cout << "Base destructor\n";
    }
};

// Derived class definition inheriting from Base
class Derived : public Base {
public:
    // Derived class default constructor
    Derived() {
        // Log construction of Derived class
        std::cout << "Derived constructor\n";
    }
    // Derived class destructor
    ~Derived() {
        // Log destruction of Derived class
        std::cout << "Derived destructor\n";
    }
};

// Main function demonstrating constructor and destructor execution order
int main() {
    // Instantiate Derived object; Base constructor runs first, then Derived constructor
    Derived object;
    // Object goes out of scope here; Derived destructor runs first, then Base destructor
    return 0;
}
