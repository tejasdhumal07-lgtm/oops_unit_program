// Concept 12: Collection of Polymorphic Shape Pointers
// Aim: To process different derived objects through a common abstract base interface.

// Include input/output stream library
#include <iostream>
// Include memory header for std::unique_ptr and std::make_unique
#include <memory>
// Include vector header for std::vector container
#include <vector>

// Abstract base class defining common interface for all shapes
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;
    // Pure virtual function to display shape name
    virtual void displayName() const = 0;
    // Virtual destructor ensuring proper resource cleanup
    virtual ~Shape() = default;
};

// Derived class Rectangle implementing Shape
class Rectangle : public Shape {
private:
    // Length dimension of rectangle
    double length;
    // Width dimension of rectangle
    double width;

public:
    // Constructor initializing dimensions
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Implementation of area() for Rectangle
    double area() const override {
        // Return product of length and width
        return length * width;
    }

    // Implementation of displayName() for Rectangle
    void displayName() const override {
        // Output type name
        std::cout << "Rectangle";
    }
};

// Derived class Circle implementing Shape
class Circle : public Shape {
private:
    // Radius dimension of circle
    double radius;

public:
    // Explicit constructor initializing radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Implementation of area() for Circle
    double area() const override {
        // Precision PI constant
        constexpr double PI = 3.141592653589793;
        // Return PI * r^2
        return PI * radius * radius;
    }

    // Implementation of displayName() for Circle
    void displayName() const override {
        // Output type name
        std::cout << "Circle";
    }
};

// Main entry point
int main() {
    // Vector holding unique smart pointers to abstract Shape interface
    std::vector<std::unique_ptr<Shape>> shapes;

    // Dynamically allocate a Rectangle (5.0 x 3.0) and move pointer into vector
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));

    // Dynamically allocate a Circle (radius 2.0) and move pointer into vector
    shapes.push_back(std::make_unique<Circle>(2.0));

    // Polymorphically iterate over each shape smart pointer in vector
    for (const auto& shape : shapes) {
        // Call virtual displayName() for current shape
        shape->displayName();
        // Call virtual area() for current shape and output result
        std::cout << " Area: " << shape->area() << '\n';
    }

    // Return 0 for success
    return 0;
}
