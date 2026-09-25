// Standard header for console output operations
#include <iostream>
// Standard header for std::string type
#include <string>
// Standard header for move utility
#include <utility>

// Base class Person with parameterized constructor
class Person {
protected:
    // Protected name member variable
    std::string name;

public:
    // Parameterized constructor initializing 'name'
    explicit Person(std::string personName) : name(std::move(personName)) {}
};

// Derived class Student inheriting from Person
class Student : public Person {
private:
    // Private variable for roll number
    int rollNumber;

public:
    // Constructor passing studentName to Person base class and initializing rollNumber
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Member function to display student details
    void display() const {
        // Output person's name
        std::cout << "Name: " << name << '\n';
        // Output student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Execution starting point
int main() {
    // Instantiate Student object with name "Kiran" and roll number 24
    Student student("Kiran", 24);
    // Print student information
    student.display();
    // Return 0 for successfully completed process
    return 0;
}
