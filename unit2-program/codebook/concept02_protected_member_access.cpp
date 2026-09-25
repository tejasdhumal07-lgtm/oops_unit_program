// Header file for input and output stream operations
#include <iostream>
// Header file for std::string class
#include <string>
// Header file for std::move utility function
#include <utility>

// Base class representing an Employee
class Employee {
protected:
    // Protected variable 'name' accessible within base and derived classes
    std::string name;

public:
    // Parameterized constructor initializing 'name' using std::move
    explicit Employee(std::string employeeName) : name(std::move(employeeName)) {}
};

// Derived class Developer inheriting publicly from Employee
class Developer : public Employee {
private:
    // Private variable 'language' specific to Developer class
    std::string language;

public:
    // Constructor invoking Employee base constructor and initializing programming language
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)), language(std::move(programmingLanguage)) {}

    // Member function to display developer details
    void display() const {
        // Output developer's name (accessed directly from protected base member)
        std::cout << "Developer: " << name << '\n';
        // Output developer's programming language
        std::cout << "Language: " << language << '\n';
    }
};

// Main function - Entry point of execution
int main() {
    // Create a Developer object with name "Neha" and language "C++"
    Developer developer("Neha", "C++");
    // Call display function to output developer details
    developer.display();
    // Return 0 to indicate program finished successfully
    return 0;
}
