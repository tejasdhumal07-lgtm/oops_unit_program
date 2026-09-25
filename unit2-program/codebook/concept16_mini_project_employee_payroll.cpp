// Header file for console stream input and output operations
#include <iostream>
// Header file for std::string type manipulation
#include <string>
// Header file for std::move utility function
#include <utility>

// Abstract base class Employee
class Employee {
protected:
    // Protected member variable for employee ID
    int employeeId;
    // Protected member variable for employee name
    std::string name;

public:
    // Constructor for Employee initializing ID and name
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function calculateSalary making Employee an abstract base class
    virtual double calculateSalary() const = 0;

    // Member function to display basic employee identification details
    void displayBasicDetails() const {
        // Output employee ID to console
        std::cout << "Employee ID: " << employeeId << '\n';
        // Output employee name to console
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor ensuring safe polymorphic destruction
    virtual ~Employee() = default;
};

// Derived class PermanentEmployee inheriting from Employee
class PermanentEmployee : public Employee {
private:
    // Private variable for monthly basic salary amount
    double basicSalary;
    // Private variable for additional allowance amount
    double allowance;

public:
    // Constructor calling base Employee constructor and initializing basic salary and allowance
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    // Overridden implementation of salary calculation for permanent employees
    double calculateSalary() const override {
        // Return sum of basic salary and allowance
        return basicSalary + allowance;
    }
};

// Derived class ContractEmployee inheriting from Employee
class ContractEmployee : public Employee {
private:
    // Private variable for hourly pay rate
    double hourlyRate;
    // Private variable for total number of hours worked
    int hoursWorked;

public:
    // Constructor calling base Employee constructor and initializing rate and hours
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // Overridden implementation of salary calculation for contract employees
    double calculateSalary() const override {
        // Return product of hourly rate and hours worked
        return hourlyRate * hoursWorked;
    }
};

// Global function accepting polymorphic base class reference to print pay slip
void displayPaySlip(const Employee& employee) {
    // Print base identification details
    employee.displayBasicDetails();
    // Dynamically dispatch and display calculated salary for specific employee type
    std::cout << "Salary: " << employee.calculateSalary() << "\n\n";
}

// Main execution block of application
int main() {
    // Instantiate a PermanentEmployee object with ID 101, name "Asha", basic 40000.0, allowance 8000.0
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
    // Instantiate a ContractEmployee object with ID 102, name "Vikas", rate 500.0, hours 80
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Call displayPaySlip function for permanent employee object
    displayPaySlip(permanentEmployee);
    // Call displayPaySlip function for contract employee object
    displayPaySlip(contractEmployee);

    // Return 0 indicating clean exit
    return 0;
}
