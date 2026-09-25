#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

class Student { // Define Student class blueprint
public: // Access specifier making members accessible from outside class
    static int count; // Static data member declaration shared by all instances of Student
    Student() { // Constructor automatically called when a Student object is instantiated
        count++; // Increment shared static variable count by 1 for every object created
    } // End of constructor
}; // End of Student class definition

int Student::count = 0; // Define and initialize static data member outside class definition to 0

int main() { // Main function: entry point of the C++ program
    Student s1, s2, s3; // Create three Student objects (s1, s2, s3), incrementing count three times
    cout << Student::count; // Output the final count value using class scope resolution operator
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function
