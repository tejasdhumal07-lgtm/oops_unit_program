// Concept 1: Function Overloading
// Aim: To implement compile-time polymorphism using function overloading.

// Include standard input-output stream library for console output operations
#include <iostream>

// Define an overloaded function 'add' that takes two integer arguments
int add(int first, int second) {
    // Add the two integer values and return the integer sum
    return first + second;
}

// Define an overloaded function 'add' that takes two double-precision floating point arguments
double add(double first, double second) {
    // Add the two double values and return the floating-point sum
    return first + second;
}

// Define an overloaded function 'add' that takes three integer arguments
int add(int first, int second, int third) {
    // Add all three integer values and return the integer sum
    return first + second + third;
}

// The main function where execution begins
int main() {
    // Invoke add(int, int) with 10 and 20, printing the result to standard output
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Invoke add(double, double) with 2.5 and 3.7, printing the result to standard output
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Invoke add(int, int, int) with 10, 20, and 30, printing the result to standard output
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    // Return 0 to indicate successful program completion
    return 0;
}
