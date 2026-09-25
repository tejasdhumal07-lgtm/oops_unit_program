// Concept 6: Relational Operator Overloading
// Aim: To overload the > operator for comparing two user-defined objects.

// Include input/output stream library
#include <iostream>

// Class Distance encapsulates a distance value in meters
class Distance {
private:
    // Private integer member storing distance in meters
    int meters;

public:
    // Explicit constructor initializing meters value
    explicit Distance(int value) : meters(value) {}

    // Overloaded greater-than (>) relational operator comparing two Distance objects
    bool operator>(const Distance& other) const {
        // Return true if this object's meters value is strictly greater than other's
        return meters > other.meters;
    }

    // Function to output the distance with units
    void display() const {
        // Output meters value with unit string
        std::cout << meters << " meters\n";
    }
};

// Entry point of program
int main() {
    // Instantiate first Distance object (120 meters)
    Distance first(120);

    // Instantiate second Distance object (90 meters)
    Distance second(90);

    // Output heading for first distance
    std::cout << "First distance: ";
    // Output value of first distance
    first.display();

    // Output heading for second distance
    std::cout << "Second distance: ";
    // Output value of second distance
    second.display();

    // Compare first and second using overloaded > operator
    if (first > second) {
        // Branch executed when first is greater than second
        std::cout << "First distance is greater\n";
    } else {
        // Branch executed when first is not greater than second
        std::cout << "Second distance is greater or equal\n";
    }

    // Return 0 for success
    return 0;
}
