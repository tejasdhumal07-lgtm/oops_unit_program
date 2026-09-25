// ============================================================================
// File: project01_employee_payroll_system.cpp
// Unit II: Inheritance - Real-Time Application 1
// Title: Employee Payroll System
// Description: Implements an employee payroll management system using object-oriented
//              programming concepts such as abstract base classes, protected members,
//              hierarchical inheritance, constructor chaining, function overriding,
//              and const correctness.
// ============================================================================

#include <iostream>     // Include iostream header for standard input/output stream operations (std::cout)
#include <string>       // Include string header for std::string string handling class
#include <string_view>  // Include string_view header for lightweight string passing without memory copying

// Define Abstract Base Class 'Employee' representing generic employee attributes and behaviors
class Employee {
protected:
    int empId;                  // Unique integer identifier for the employee (accessible in derived classes)
    std::string name;           // Name of the employee (accessible in derived classes)
    std::string department;     // Department name of the employee (accessible in derived classes)

public:
    // Parameterized Constructor: initializes base class attributes using member initializer list
    Employee(int id, std::string_view n, std::string_view dept)
        : empId(id), name(n), department(dept) {} // Execute constructor body after initialization list

    // Display function to print basic details common to all employees
    void displayBasicInfo() const {
        std::cout << "ID: " << empId               // Output employee ID to console
                  << " | Name: " << name           // Output employee name to console
                  << " | Department: " << department; // Output employee department without trailing newline
    }

    // Pure Virtual Function: enforces salary calculation implementation in all concrete derived classes
    virtual double calculateSalary() const = 0;

    // Virtual Destructor: ensures proper cleanup of derived objects when deleted via base class pointer
    virtual ~Employee() = default;
};

// Derived Class 'FullTimeEmployee': inherits publicly from base class 'Employee'
class FullTimeEmployee : public Employee {
private:
    double monthlySalary; // Fixed monthly salary private attribute specific to full-time employees

public:
    // Parameterized Constructor: chains to base class constructor and initializes monthlySalary
    FullTimeEmployee(int id, std::string_view n, std::string_view dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {} // Initialize base attributes and monthly salary

    // Override pure virtual function to calculate salary for full-time employee
    double calculateSalary() const override {
        return monthlySalary; // Return the fixed monthly salary amount
    }

    // Display complete details for full-time employee
    void display() const {
        displayBasicInfo(); // Print common basic employee information
        std::cout << " | Type: Full-Time | Salary: Rs. " // Print employment type and currency label
                  << calculateSalary() << '\n';           // Print calculated salary followed by newline
    }
};

// Derived Class 'PartTimeEmployee': inherits publicly from base class 'Employee'
class PartTimeEmployee : public Employee {
private:
    double hourlyRate; // Hourly pay rate for part-time work
    int hoursWorked;   // Total number of hours worked

public:
    // Parameterized Constructor: chains to base class constructor and initializes hourly parameters
    PartTimeEmployee(int id, std::string_view n, std::string_view dept, double rate, int hours)
        : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {} // Initialize members

    // Override pure virtual function to calculate salary based on hourly rate and hours worked
    double calculateSalary() const override {
        return hourlyRate * hoursWorked; // Multiply rate by total hours worked to get total pay
    }

    // Display complete details for part-time employee
    void display() const {
        displayBasicInfo(); // Print common basic employee information
        std::cout << " | Type: Part-Time | Salary: Rs. " // Print employment type and currency label
                  << calculateSalary() << '\n';           // Print calculated total pay followed by newline
    }
};

// Derived Class 'Intern': inherits publicly from base class 'Employee'
class Intern : public Employee {
private:
    double stipend; // Fixed monthly stipend specific to interns

public:
    // Parameterized Constructor: chains to base class constructor and initializes stipend
    Intern(int id, std::string_view n, std::string_view dept, double stipendAmount)
        : Employee(id, n, dept), stipend(stipendAmount) {} // Initialize base attributes and stipend amount

    // Override pure virtual function to calculate salary (stipend) for intern
    double calculateSalary() const override {
        return stipend; // Return the fixed stipend amount
    }

    // Display complete details for intern
    void display() const {
        displayBasicInfo(); // Print common basic employee information
        std::cout << " | Type: Intern | Stipend: Rs. " // Print employment type and stipend label
                  << calculateSalary() << '\n';         // Print calculated stipend followed by newline
    }
};

// Main execution function
int main() {
    // Instantiate FullTimeEmployee object with ID 101, name "Amit", dept "IT", salary 65000
    FullTimeEmployee f1(101, "Amit", "IT", 65000);

    // Instantiate PartTimeEmployee object with ID 102, name "Sneha", dept "HR", rate 250, hours 120
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);

    // Instantiate Intern object with ID 103, name "Rohan", dept "Marketing", stipend 15000
    Intern i1(103, "Rohan", "Marketing", 15000);

    // Output title banner header to standard output stream
    std::cout << "=== Employee Payroll ===" << '\n';

    // Display payroll details for full-time employee f1
    f1.display();

    // Display payroll details for part-time employee p1
    p1.display();

    // Display payroll details for intern i1
    i1.display();

    // Return 0 to OS indicating successful program completion
    return 0;
}
