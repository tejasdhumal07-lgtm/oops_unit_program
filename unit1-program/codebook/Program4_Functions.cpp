#include <iostream> // Header file for input and output stream operations
using namespace std; // Use standard namespace to avoid std:: prefix

int add(int, int); // Function prototype declaration informing compiler of function signature

int main() { // Main function: entry point of the C++ program
    int a = 10, b = 20; // Declare two integer variables 'a' and 'b' initialized to 10 and 20
    cout << "Sum = " << add(a, b) << endl; // Call add function passing a and b, print returned sum with newline
    return 0; // Return 0 to OS indicating successful program execution
} // End of main function

int add(int x, int y) { // Function definition of add taking two integer parameters x and y
    return x + y; // Return the calculated sum of x and y back to the caller
} // End of add function
