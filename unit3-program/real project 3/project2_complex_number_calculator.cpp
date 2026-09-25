// ============================================================================
// Unit III - Real-Time Application 2: Complex Number Calculator
// ============================================================================
// Description: Demonstrates compile-time polymorphism through operator overloading
// (binary +, -, *, and ==) for a custom Complex number class.
// ============================================================================

// Include standard input-output stream library for printing complex numbers (std::cout, std::endl)
#include <iostream>

// Use standard namespace to allow direct usage of cout and endl without std:: prefix
using namespace std;

// Class representing a complex mathematical number of the form (real + imag * i)
class Complex {
private:
    // Private data member storing real part of complex number
    double real;

    // Private data member storing imaginary part of complex number
    double imag;

public:
    // Parameterized constructor with default arguments (0.0 for both real and imag)
    // Uses member initializer list for efficient attribute initialization
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload addition (+) operator to add two Complex objects
    // Returns a new Complex object representing the sum
    // Marked const because it does not modify the calling object (lhs)
    Complex operator+(const Complex& other) const {
        // Return new Complex object with summed real parts and summed imaginary parts
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload subtraction (-) operator to subtract other Complex object from caller
    // Returns a new Complex object representing the difference
    Complex operator-(const Complex& other) const {
        // Return new Complex object with subtracted real parts and subtracted imaginary parts
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload multiplication (*) operator for complex multiplication formula:
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& other) const {
        // Return new Complex object constructed from calculated real and imaginary components
        return Complex(
            real * other.real - imag * other.imag, // Calculated real part: ac - bd
            real * other.imag + imag * other.real  // Calculated imaginary part: ad + bc
        );
    }

    // Overload equality (==) operator to check if two Complex numbers are identical
    // Returns true if both real and imaginary components match
    bool operator==(const Complex& other) const {
        // Evaluate logical AND condition between real parts equality and imaginary parts equality
        return real == other.real && imag == other.imag;
    }

    // Member function to display the complex number in "a + bi" standard format
    // Marked const as it only reads data members to output stream
    void display() const {
        // Print real part, formatted plus sign with spaces, imaginary part, 'i', and newline
        cout << real << " + " << imag << "i" << endl;
    }
};

// Main function: Program execution start point
int main() {
    // Instantiate first Complex object c1 with real=3.0 and imag=4.0
    Complex c1(3.0, 4.0);

    // Instantiate second Complex object c2 with real=1.0 and imag=2.0
    Complex c2(1.0, 2.0);

    // Display label for first complex number
    cout << "C1: ";
    // Call display() on c1 to output "3 + 4i"
    c1.display();

    // Display label for second complex number
    cout << "C2: ";
    // Call display() on c2 to output "1 + 2i"
    c2.display();

    // Display label for addition result
    cout << "Sum: ";
    // Invoke overloaded operator+ on c1 and c2, then immediately display returned object ("4 + 6i")
    (c1 + c2).display();

    // Display label for subtraction result
    cout << "Difference: ";
    // Invoke overloaded operator- on c1 and c2, then immediately display returned object ("2 + 2i")
    (c1 - c2).display();

    // Display label for multiplication result
    cout << "Product: ";
    // Invoke overloaded operator* on c1 and c2, then immediately display returned object ("-5 + 10i")
    (c1 * c2).display();

    // Return 0 indicating successful program execution
    return 0;
}
