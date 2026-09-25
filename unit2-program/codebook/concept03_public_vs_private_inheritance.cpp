// Include standard input-output stream library
#include <iostream>

// Base class definition
class Base {
public:
    // Public member function of Base class
    void show() const {
        // Output text to console
        std::cout << "Base public function\n";
    }
};

// Derived class using public inheritance mode
class PublicDerived : public Base {
    // Inherits Base publicly, so show() remains public in PublicDerived
};

// Derived class using private inheritance mode
class PrivateDerived : private Base {
public:
    // Public wrapper function inside PrivateDerived
    void callBaseShow() const {
        // show() is private within PrivateDerived, but accessible inside its member functions
        show();
    }
};

// Main function
int main() {
    // Instantiate object of PublicDerived class
    PublicDerived publicObject;
    // Call show() directly since public inheritance preserves public access
    publicObject.show();

    // Instantiate object of PrivateDerived class
    PrivateDerived privateObject;
    // Call wrapper function which internally invokes private Base::show()
    privateObject.callBaseShow();

    // // privateObject.show(); // Error: show() is private through private inheritance.

    // Return 0 indicating successful completion
    return 0;
}
