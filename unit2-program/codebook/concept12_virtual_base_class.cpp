// Standard I/O operations library
#include <iostream>
// Standard string library
#include <string>
// Standard move semantics library
#include <utility>

// Base class Person at the top of diamond inheritance structure
class Person {
protected:
    // Protected member name shared across derived classes
    std::string name;

public:
    // Constructor initializing personName using move semantics
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Member function to display name
    void displayName() const {
        // Output person's name to console
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class Student inheriting virtually from Person to avoid duplicate sub-objects
class Student : virtual public Person {
public:
    // Default constructor providing placeholder name to Person base
    Student() : Person("Unknown") {}
};

// Derived class Employee inheriting virtually from Person to avoid duplicate sub-objects
class Employee : virtual public Person {
public:
    // Default constructor providing placeholder name to Person base
    Employee() : Person("Unknown") {}
};

// Class TeachingAssistant inheriting from both Student and Employee (Diamond inheritance resolved by virtual base)
class TeachingAssistant : public Student, public Employee {
public:
    // Constructor explicitly initializing the single shared Person virtual base class
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)), Student(), Employee() {}
};

// Main function
int main() {
    // Instantiate TeachingAssistant object with name "Riya"
    TeachingAssistant assistant("Riya");
    // Call displayName method inherited without ambiguity from virtual base Person
    assistant.displayName();
    // Return status 0
    return 0;
}
