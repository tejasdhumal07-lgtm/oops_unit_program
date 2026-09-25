// Concept 16: Employee Payroll Mini-Project
// Aim: To build a salary-calculation application using abstract classes and run-time polymorphism.

// Include input/output stream operations
#include <iostream>
// Include string library
#include <string>
// Include utility header for std::move
#include <utility>

// Abstract base class Employee storing shared metadata and salary interface
class Employee {
protected:
    // Protected member storing unique employee ID
    int employeeId;
    // Protected member storing employee name
    std::string name;

public:
    // Constructor initializing employee ID and moving string name into member variable
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function enforcing custom salary calculation logic in subclasses
    virtual double calculateSalary() const = 0;

    // Const function displaying common employee details
    void displayBasicDetails() const {
        // Output employee ID
        std::cout << "Employee ID: " << employeeId << '\n';
        // Output employee name
        std::cout << "Name: " << name << '\n';
    }

    // Default virtual destructor for safe polymorphic destruction
    virtual ~Employee() = default;
};

// Subclass representing salaried permanent staff
class PermanentEmployee : public Employee {
private:
    // Base salary portion
    double basicSalary;
    // Additional allowance component
    double allowance;

public:
    // Constructor passing basic parameters to base class and setting specific members
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}

    // Overridden calculateSalary combining basic salary and allowance
    double calculateSalary() const override {
        // Return sum of basic salary and allowance
        return basicSalary + allowance;
    }
};

// Subclass representing hourly contract staff
class ContractEmployee : public Employee {
private:
    // Hourly pay rate
    double hourlyRate;
    // Total hours worked
    int hoursWorked;

public:
    // Constructor setting hourly rate and hours worked alongside base details
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}

    // Overridden calculateSalary multiplying hourly rate by hours worked
    double calculateSalary() const override {
        // Return product of hourly rate and hours worked
        return hourlyRate * hoursWorked;
    }
};

// Standalone function generating payslip via polymorphic base reference
void printPaySlip(const Employee& employee) {
    // Print common employee details (ID and Name)
    employee.displayBasicDetails();
    // Polymorphically compute and print calculated salary, followed by double newline
    std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

// Application main entry point
int main() {
    // Create Permanent Employee (ID 101, Asha, 40000.0 basic, 8000.0 allowance)
    PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);

    // Create Contract Employee (ID 102, Vikas, 500.0 rate, 80 hours)
    ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

    // Print payslip for permanent employee
    printPaySlip(permanentEmployee);

    // Print payslip for contract employee
    printPaySlip(contractEmployee);

    // Return status 0
    return 0;
}
