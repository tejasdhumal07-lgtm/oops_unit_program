// Header for input/output console operations
#include <iostream>
// Header for standard string class
#include <string>
// Header for standard move semantics utility
#include <utility>

// Top base class Person
class Person {
protected:
    // Protected member string 'name'
    std::string name;

public:
    // Constructor for Person class taking personName
    explicit Person(std::string personName) : name(std::move(personName)) {}

    // Member function to display person's name
    void showPerson() const {
        // Output name to console
        std::cout << "Name: " << name << '\n';
    }
};

// Intermediate derived class Employee inheriting from Person
class Employee : public Person {
protected:
    // Protected member variable for employee ID
    int employeeId;

public:
    // Constructor for Employee calling Person base constructor
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {}

    // Member function to display employee ID
    void showEmployee() const {
        // Output employee ID to console
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Bottom derived class Manager inheriting from Employee
class Manager : public Employee {
private:
    // Private member variable for size of managed team
    int teamSize;

public:
    // Constructor for Manager calling Employee constructor
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {}

    // Member function to display all manager details
    void showManager() const {
        // Call grandparent function to print name
        showPerson();
        // Call parent function to print employee ID
        showEmployee();
        // Output team size to console
        std::cout << "Team Size: " << teamSize << '\n';
    }
};

// Entry point of program
int main() {
    // Instantiate Manager object with name "Ravi", ID 501, team size 8
    Manager manager("Ravi", 501, 8);
    // Display all information using showManager method
    manager.showManager();
    // Return 0 for success
    return 0;
}
