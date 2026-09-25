// Concept 4: Prefix and Postfix Increment Operator Overloading
// Aim: To overload prefix and postfix increment operators.

// Include iostream header for stream operations
#include <iostream>

// Class Counter encapsulates an integer value and overloads ++ operators
class Counter {
private:
    // Member variable storing the current counter value
    int value;

public:
    // Explicit constructor initializing value, default parameter is 0
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // Overloaded Prefix increment (++c): increments state first, returns reference to *this
    Counter& operator++() {
        // Pre-increment internal value member
        ++value;
        // Return reference to updated object
        return *this;
    }

    // Overloaded Postfix increment (c++): dummy int parameter distinguishes it from prefix
    Counter operator++(int) {
        // Make a copy of current object state before mutating
        Counter old = *this;
        // Pre-increment internal value member
        ++value;
        // Return un-incremented copy of object
        return old;
    }

    // Const function displaying current stored value
    void display() const {
        // Print value to output stream
        std::cout << value << '\n';
    }
};

// Main function entry point
int main() {
    // Instantiate Counter object initialized with value 5
    Counter counter(5);

    // Output message heading for prefix increment
    std::cout << "After prefix increment: ";
    // Execute prefix increment ++counter
    ++counter;
    // Display value after prefix increment
    counter.display();

    // Output message heading for returned value of postfix increment
    std::cout << "Value returned by postfix increment: ";
    // Execute postfix increment counter++ and store pre-increment state into oldValue
    Counter oldValue = counter++;
    // Display saved old value
    oldValue.display();

    // Output message heading for counter state after postfix operation completes
    std::cout << "Counter after postfix increment: ";
    // Display modified counter value
    counter.display();

    // Return status 0 for successful execution
    return 0;
}
