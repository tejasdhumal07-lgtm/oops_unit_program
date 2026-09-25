// ============================================================================
// Unit III - Real-Time Application 3: Input Validation Service
// ============================================================================
// Description: Demonstrates compile-time function overloading polymorphism by
// providing a common validate() interface for different input data types
// (integer marks, double payment amounts, and string names).
// ============================================================================

// Include character handling library for character classification function isalpha()
#include <cctype>

// Include standard stream library for outputting validation test results (std::cout, std::endl, std::boolalpha)
#include <iostream>

// Include string library to work with standard string objects (std::string)
#include <string>

// Use standard namespace to avoid prefixing std:: throughout the source file
using namespace std;

// Class providing input validation methods overloaded for various data types
class Validator {
public:
    // Overloaded validate function for integer student marks
    // Validates that marks fall within valid percentage range [0, 100]
    // Marked const because validation does not alter Validator state
    bool validate(int marks) const {
        // Return true if marks are greater than/equal to 0 AND less than/equal to 100
        return marks >= 0 && marks <= 100;
    }

    // Overloaded validate function for double payment transaction amounts
    // Validates that payment amount is positive (> 0.0) and within upper transaction limit (<= 1,000,000.0)
    bool validate(double amount) const {
        // Return true if amount is greater than 0.0 AND less than or equal to 1000000.0
        return amount > 0.0 && amount <= 1000000.0;
    }

    // Overloaded validate function for user/person name strings
    // Validates that name string is non-empty and contains only alphabetic characters and spaces
    bool validate(const string& name) const {
        // Check if input name string is empty
        if (name.empty()) {
            // Return false for empty string input
            return false;
        }

        // Range-based for loop iterating over each character in input string
        for (char ch : name) {
            // Check if character is NOT an alphabetic letter AND NOT a space character
            // static_cast to unsigned char prevents undefined behavior with negative char values in isalpha
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ') {
                // Return false if any invalid character (digit, symbol, etc.) is found
                return false;
            }
        }

        // Return true if all characters passed validation check
        return true;
    }
};

// Main function: Entry point of the validation service program
int main() {
    // Instantiate Validator object
    Validator validator;

    // Set std::boolalpha manipulator on cout stream so boolean values format as "true"/"false" instead of 1/0
    cout << boolalpha;

    // Validate integer marks 88 (valid range 0-100) and display result ("true")
    cout << "Marks 88 valid: " << validator.validate(88) << endl;

    // Validate integer marks 120 (exceeds max 100) and display result ("false")
    cout << "Marks 120 valid: " << validator.validate(120) << endl;

    // Validate payment amount 4500.50 (valid range 0.0 - 1000000.0) and display result ("true")
    cout << "Amount 4500.50 valid: " << validator.validate(4500.50) << endl;

    // Validate string name "Priya Sharma" (contains valid letters and space) and display result ("true")
    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma")) << endl;

    // Validate string name "Priya123" (contains invalid numeric digits) and display result ("false")
    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123")) << endl;

    // Return 0 indicating successful completion of main function
    return 0;
}
