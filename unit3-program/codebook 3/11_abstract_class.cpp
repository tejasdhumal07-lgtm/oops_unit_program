// Concept 11: Abstract Class and Pure Virtual Function
// Aim: To create and use an abstract class.

// Include standard stream I/O header
#include <iostream>

// Abstract base class Shape (contains at least one pure virtual function)
class Shape {
public:
    // Pure virtual function (= 0) enforcing implementation in derived classes
    virtual double area() const = 0;

    // Virtual destructor for cleanup safety
    virtual ~Shape() = default;
};

// Concrete derived class Rectangle implementing Shape interface
class Rectangle : public Shape {
private:
    // Private member storing length
    double length;
    // Private member storing width
    double width;

public:
    // Constructor initializing length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Override pure virtual function area()
    double area() const override {
        // Calculate rectangle area (length * width)
        return length * width;
    }
};

// Main function entry point
int main() {
    // Instantiate concrete Rectangle object with 8.0 length and 4.0 width
    Rectangle rectangle(8.0, 4.0);

    // Call area() on rectangle instance and output result
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    // Return 0 for success
    return 0;
}
