// Concept 2: Area Calculator Using Function Overloading
// Aim: To calculate areas of different shapes using overloaded functions.

// Include stream I/O library for printing output to console
#include <iostream>

// Function to calculate the area of a square given integer side length
int calculateArea(int side) {
    // Calculate and return area (side * side)
    return side * side;
}

// Function to calculate the area of a rectangle given length and width
int calculateArea(int length, int width) {
    // Calculate and return area (length * width)
    return length * width;
}

// Function to calculate the area of a circle given double-precision radius
double calculateArea(double radius) {
    // Define exact value of PI as a compile-time constant
    constexpr double PI = 3.141592653589793;
    // Calculate and return area (PI * radius * radius)
    return PI * radius * radius;
}

// Main function serving as program entry point
int main() {
    // Call calculateArea(int) for square with side 5 and print result
    std::cout << "Square Area: " << calculateArea(5) << '\n';

    // Call calculateArea(int, int) for rectangle with 6 and 4 and print result
    std::cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';

    // Call calculateArea(double) for circle with radius 2.0 and print result
    std::cout << "Circle Area: " << calculateArea(2.0) << '\n';

    // Return 0 indicating normal termination
    return 0;
}
