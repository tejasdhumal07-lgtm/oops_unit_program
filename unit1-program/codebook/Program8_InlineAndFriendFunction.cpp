#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

class Test { // Define Test class blueprint
private: // Private access specifier: members accessible only within class
    int value; // Private data member to store an integer value
public: // Public access specifier: members accessible from outside class
    Test(int v) { // Parameterized constructor to initialize value member
        value = v; // Assign value passed to argument v into data member value
    } // End of constructor
    inline int getValue() { // Inline member function definition to return value
        return value; // Return private member value
    } // End of inline getValue function
    friend void show(Test t); // Declare show function as friend, granting access to private members
}; // End of Test class definition

void show(Test t) { // Friend function definition taking Test object as parameter
    cout << t.value; // Access and print private member value directly
} // End of friend function show

int main() { // Main function: entry point of the C++ program
    Test obj(50); // Create Test object 'obj' passing 50 to parameterized constructor
    cout << obj.getValue() << endl; // Call inline getter function getValue and print result with newline
    show(obj); // Call friend function show passing obj to display private value
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function
