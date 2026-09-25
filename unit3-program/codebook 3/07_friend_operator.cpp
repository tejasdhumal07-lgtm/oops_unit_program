// Concept 7: Friend/Non-Member Operator Overloading
// Aim: To overload an operator using a friend non-member function.

// Include standard input/output library
#include <iostream>

// Class representing Complex number supporting left-operand integer addition
class Complex {
private:
    // Private member storing real part
    int real;
    // Private member storing imaginary part
    int imaginary;

public:
    // Constructor initializing real and imaginary parts with defaults 0
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Declare friend non-member operator+ enabling (int + Complex) expressions
    friend Complex operator+(int value, const Complex& number);

    // Const function displaying the formatted complex number
    void display() const {
        // Output real part
        std::cout << real;
        // Check sign of imaginary part
        if (imaginary >= 0) {
            // Print positive join operator
            std::cout << " + ";
        } else {
            // Print negative join operator
            std::cout << " - ";
        }
        // Output magnitude of imaginary component followed by 'i' and newline
        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

// Non-member friend function definition overloading binary + for (int + Complex)
Complex operator+(int value, const Complex& number) {
    // Access private members directly and return new Complex object
    return Complex(value + number.real, number.imaginary);
}

// Entry point of program
int main() {
    // Instantiate Complex number (2 + 3i)
    Complex number(2, 3);

    // Perform addition between primitive integer 10 and Complex object 'number'
    Complex result = 10 + number;

    // Print description label
    std::cout << "Result: ";
    // Output calculation result
    result.display();

    // Return 0 indicating successful execution
    return 0;
}
