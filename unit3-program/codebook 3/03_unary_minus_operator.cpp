// Concept 3: Unary Minus Operator Overloading
// Aim: To overload a unary minus operator for a user-defined class.

// Include iostream header to enable console input/output operations
#include <iostream>

// Class representing a numerical value with overloaded unary operator support
class Number {
private:
    // Private data member storing the internal integer value
    int value;

public:
    // Constructor taking an initial integer value; explicit prevents implicit conversions
    explicit Number(int givenValue) : value(givenValue) {}

    // Overloaded unary minus (-) operator function returning a new Number with negated value
    Number operator-() const {
        // Construct and return a new Number object containing -value
        return Number(-value);
    }

    // Const member function to output the internal value to the console
    void display() const {
        // Output value followed by a newline character
        std::cout << value << '\n';
    }
};

// Entry point of the C++ application
int main() {
    // Create an instance 'first' of class Number initialized to 25
    Number first(25);

    // Call overloaded unary minus operator on 'first' (-first) and assign result to 'second'
    Number second = -first;

    // Output descriptive text for original value
    std::cout << "Original value: ";
    // Print value stored in 'first'
    first.display();

    // Output descriptive text for negated value
    std::cout << "Negated value: ";
    // Print value stored in 'second'
    second.display();

    // Return 0 to indicate successful program execution
    return 0;
}
