// Concept 5: Binary + Operator Overloading for Complex Numbers
// Aim: To overload the binary + operator to add two complex numbers.

// Include standard input/output stream library
#include <iostream>

// Class representing a mathematical complex number (real + imaginary parts)
class Complex {
private:
    // Private integer member storing the real component
    int real;
    // Private integer member storing the imaginary component
    int imaginary;

public:
    // Constructor with default parameters for real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overloaded binary addition (+) operator function
    Complex operator+(const Complex& other) const {
        // Return a new Complex object with sums of real and imaginary parts
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Member function to print the complex number in "a + bi" or "a - bi" format
    void display() const {
        // Print the real part
        std::cout << real;
        // Check if imaginary part is non-negative
        if (imaginary >= 0) {
            // Print addition sign for positive imaginary part
            std::cout << " + ";
        } else {
            // Print subtraction sign for negative imaginary part
            std::cout << " - ";
        }
        // Print magnitude of imaginary part followed by 'i' and a newline
        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

// Main function serving as application entry point
int main() {
    // Instantiate first complex number (2 + 3i)
    Complex first(2, 3);

    // Instantiate second complex number (4 + 5i)
    Complex second(4, 5);

    // Add first and second complex numbers using binary + operator
    Complex sum = first + second;

    // Display descriptive text for first complex number
    std::cout << "First complex number: ";
    // Output first complex number
    first.display();

    // Display descriptive text for second complex number
    std::cout << "Second complex number: ";
    // Output second complex number
    second.display();

    // Display descriptive text for sum
    std::cout << "Sum: ";
    // Output sum complex number
    sum.display();

    // Return 0 for success
    return 0;
}
