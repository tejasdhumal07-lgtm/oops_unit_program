#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

class Student { // Define Student class blueprint
public: // Access specifier making members accessible from outside class
    string name; // Member variable to store student's name
    int age; // Member variable to store student's age
    void show() { // Member function to display student information
        cout << name << " " << age << endl; // Print student name and age separated by space with newline
    } // End of show function
}; // End of Student class definition

int main() { // Main function: entry point of the C++ program
    Student s1; // Instantiate object 's1' of class Student
    s1.name = "Amit"; // Assign string value "Amit" to object s1's name member
    s1.age = 20; // Assign integer value 20 to object s1's age member
    s1.show(); // Call show member function of s1 to print details
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function
