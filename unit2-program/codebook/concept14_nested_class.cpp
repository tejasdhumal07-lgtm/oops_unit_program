// Include iostream header for output functions
#include <iostream>
// Include string header for std::string type
#include <string>
// Include utility header for move semantics
#include <utility>

// Enclosing outer class University
class University {
public:
    // Nested inner class Department declared inside University
    class Department {
    private:
        // Private member variable for department name
        std::string name;

    public:
        // Constructor for Department nested class
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}

        // Member function to display department name
        void display() const {
            // Output department name to standard console
            std::cout << "Department: " << name << '\n';
        }
    };
};

// Main function
int main() {
    // Instantiate nested class object using scope resolution operator University::Department
    University::Department department("Artificial Intelligence and Data Science");
    // Call display function on nested class object
    department.display();
    // Return status 0
    return 0;
}
