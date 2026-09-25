// Include library for console output operations
#include <iostream>

// Base class Academic
class Academic {
public:
    // Member function named display in Academic class
    void display() const {
        // Output text from Academic class
        std::cout << "Academic information\n";
    }
};

// Base class Sports
class Sports {
public:
    // Member function named display in Sports class (same name as in Academic)
    void display() const {
        // Output text from Sports class
        std::cout << "Sports information\n";
    }
};

// Derived class Student inheriting from both Academic and Sports
class Student : public Academic, public Sports {
public:
    // Member function to resolve and display output from both base classes
    void displayAll() const {
        // Explicitly invoke display() from Academic base class using scope resolution operator
        Academic::display();
        // Explicitly invoke display() from Sports base class using scope resolution operator
        Sports::display();
    }
};

// Program entry point
int main() {
    // Create Student object
    Student student;
    // Disambiguate call to display() from Academic class using scope resolution operator
    student.Academic::display();
    // Disambiguate call to display() from Sports class using scope resolution operator
    student.Sports::display();
    // Call method that internally calls both displays explicitly
    student.displayAll();
    // Return status 0
    return 0;
}
