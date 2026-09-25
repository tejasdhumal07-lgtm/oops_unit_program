#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

int main() { // Main function: entry point of the C++ program
    int marks = 45; // Declare integer variable 'marks' and initialize it to 45
    if (marks >= 40) { // Check if student marks are greater than or equal to passing mark (40)
        cout << "Pass"; // Output "Pass" to console if condition is true
    } else { // Branch executed if condition (marks >= 40) is false
        cout << "Fail"; // Output "Fail" to console if marks are below 40
    } // End of if-else block
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function
