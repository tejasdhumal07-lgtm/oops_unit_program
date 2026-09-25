// Header for console standard output stream operations
#include <iostream>

// Abstract base class Shape containing a pure virtual function
class Shape {
public:
    // Pure virtual function area() making Shape an abstract class
    virtual double area() const = 0;
    // Virtual destructor for safe polymorphic destruction
    virtual ~Shape() = default;
};

// Derived class Rectangle providing implementation for pure virtual function
class Rectangle : public Shape {
private:
    // Private member variable for length
    double length;
    // Private member variable for width
    double width;

public:
    // Constructor initializing rectangle dimensions
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overridden area() calculation implementation for Rectangle
    double area() const override {
        // Calculate and return area of rectangle (length * width)
        return length * width;
    }
};

// Derived class Circle providing implementation for pure virtual function
class Circle : public Shape {
private:
    // Private member variable for radius
    double radius;

public:
    // Explicit constructor initializing circle radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Overridden area() calculation implementation for Circle
    double area() const override {
        // Calculate and return area of circle (pi * radius^2)
        return 3.141592653589793 * radius * radius;
    }
};

// Program entry main function
int main() {
    // Instantiate Rectangle object with length 5.0 and width 3.0
    Rectangle rectangle(5.0, 3.0);
    // Instantiate Circle object with radius 2.0
    Circle circle(2.0);

    // Print calculated area of rectangle
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';
    // Print calculated area of circle
    std::cout << "Circle Area: " << circle.area() << '\n';
    // Return 0 for program success
    return 0;
}
