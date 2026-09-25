// Concept 10: Base Reference With Virtual Function
// Aim: To use a base-class reference for run-time polymorphism.

// Include input-output stream library
#include <iostream>

// Base class Shape establishing area interface
class Shape {
public:
    // Virtual function returning default area 0.0
    virtual double area() const {
        // Default implementation
        return 0.0;
    }

    // Default virtual destructor
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    // Private member for length
    double length;
    // Private member for width
    double width;

public:
    // Constructor initializing rectangle dimensions
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overridden area() function calculating rectangle area
    double area() const override {
        // Return product of length and width
        return length * width;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    // Private member for radius
    double radius;

public:
    // Explicit constructor initializing circle radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Overridden area() function calculating circle area
    double area() const override {
        // Compile-time constant for PI
        constexpr double PI = 3.141592653589793;
        // Return PI * r^2
        return PI * radius * radius;
    }
};

// Standalone function taking a reference to base class Shape
void printArea(const Shape& shape) {
    // Polymorphic invocation of area() via const reference avoids slicing
    std::cout << "Area: " << shape.area() << '\n';
}

// Main execution entry point
int main() {
    // Instantiate Rectangle with dimensions 5.0 and 3.0
    Rectangle rectangle(5.0, 3.0);

    // Instantiate Circle with radius 2.0
    Circle circle(2.0);

    // Pass Rectangle object to printArea by reference
    printArea(rectangle);

    // Pass Circle object to printArea by reference
    printArea(circle);

    // Return 0 for success
    return 0;
}
