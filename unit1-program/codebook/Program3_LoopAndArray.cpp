#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

int main() { // Main function: entry point of the C++ program
    int marks[5] = {78, 82, 91, 67, 88}; // Declare integer array 'marks' of size 5 and initialize with test scores
    for (int i = 0; i < 5; i++) { // Loop from index i = 0 up to i < 5, incrementing i by 1 each iteration
        cout << marks[i] << " "; // Output current array element followed by a space
    } // End of for loop
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function
