// Header file for input and output stream operations
#include <iostream>
// Header file for using std::string data type
#include <string>
// Header file for std::move utility function
#include <utility>

// Define the base class Person
class Person {
protected:
    // Protected member variable accessible inside Person and derived classes
    std::string name;

public:
    // Constructor for Person initializing the name variable using std::move
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Member function to print the person's name
    void displayName() const {
        // Output the name to standard output console
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class Student inheriting publicly from base class Person
class Student : public Person {
private:
    // Private member variable specific to Student class
    int rollNumber;

public:
    // Constructor for Student forwarding studentName to Person base class constructor and initializing rollNumber
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Member function to display student details
    void displayStudent() const {
        // Call base class member function to display name
        displayName();
        // Print the roll number to standard output console
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function - Entry point of the C++ program
int main() {
    // Instantiate a Student object named student with name "Amit" and roll number 101
    Student student("Amit", 101);
    // Call displayStudent method to display all details
    student.displayStudent();
    // Return 0 indicating successful execution
    return 0;
}
