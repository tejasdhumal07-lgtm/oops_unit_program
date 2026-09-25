#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

class Demo { // Define Demo class blueprint
public: // Access specifier making members accessible from outside class
    Demo() { // Constructor automatically called when Demo object is created
        cout << "Constructor called\n"; // Print message indicating constructor execution
    } // End of constructor
    ~Demo() { // Destructor automatically called when Demo object goes out of scope
        cout << "Destructor called\n"; // Print message indicating destructor execution
    } // End of destructor
}; // End of Demo class definition

int main() { // Main function: entry point of the C++ program
    Demo d; // Instantiate object 'd' of Demo class (triggers constructor)
    return 0; // Return 0 to OS; object 'd' goes out of scope here (triggers destructor)
} // End of main function
