// ============================================================================
// Unit III - Real-Time Application 1: CAD Shape Drawing System
// ============================================================================
// Description: Demonstrates runtime polymorphism using an abstract base class
// (Shape) and derived classes (Circle, Rectangle, Triangle).
// ============================================================================

// Include standard input-output stream library for console output (std::cout, std::endl)
#include <iostream>

// Include memory header for smart pointer management (std::unique_ptr, std::make_unique)
#include <memory>

// Include vector header to use std::vector dynamic array container
#include <vector>

// Use standard namespace to avoid prefixing std:: before standard library functions and classes
using namespace std;

// Define an abstract base class named Shape representing generic CAD geometric shapes
class Shape {
public:
    // Pure virtual function to calculate the surface area of a shape
    // Marked as const because area calculation does not modify object state
    // Assigned = 0 making Shape an abstract base class that cannot be instantiated directly
    virtual double area() const = 0;

    // Pure virtual function to draw/render the shape to output
    // Marked as const because rendering does not mutate shape properties
    // Derived classes must provide their own specific drawing implementation
    virtual void draw() const = 0;

    // Virtual destructor to ensure proper cleanup of derived class objects 
    // when deleted through a base class pointer
    virtual ~Shape() = default;
};

// Define derived class Circle inheriting publicly from abstract base class Shape
class Circle : public Shape {
private:
    // Private data member storing the radius of the circle
    double radius;

public:
    // Parameterized constructor initializing the circle's radius using member initializer list
    // 'explicit' keyword prevents implicit type conversions during object creation
    explicit Circle(double r) : radius(r) {}

    // Overridden area() method calculating area using formula: PI * r^2
    // Marked override to explicitly tell compiler this overrides base class virtual function
    double area() const override {
        // Return calculated circle area using double-precision floating point constant for PI
        return 3.14159265359 * radius * radius;
    }

    // Overridden draw() method displaying circle details to standard output stream
    void draw() const override {
        // Output text description of drawing action with circle radius
        cout << "Drawing circle with radius " << radius << endl;
    }
};

// Define derived class Rectangle inheriting publicly from abstract base class Shape
class Rectangle : public Shape {
private:
    // Private data member storing length of the rectangle
    double length;

    // Private data member storing width of the rectangle
    double width;

public:
    // Parameterized constructor initializing length and width via member initializer list
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overridden area() method calculating rectangle area: length * width
    double area() const override {
        // Return product of length and width
        return length * width;
    }

    // Overridden draw() method displaying rectangle dimensions to output stream
    void draw() const override {
        // Output text description of drawing action with rectangle length and width
        cout << "Drawing rectangle " << length << " x " << width << endl;
    }
};

// Define derived class Triangle inheriting publicly from abstract base class Shape
class Triangle : public Shape {
private:
    // Private data member storing base length of the triangle
    double base;

    // Private data member storing height of the triangle
    double height;

public:
    // Parameterized constructor initializing base and height via member initializer list
    Triangle(double b, double h) : base(b), height(h) {}

    // Overridden area() method calculating triangle area: 0.5 * base * height
    double area() const override {
        // Return calculated area using half base times height
        return 0.5 * base * height;
    }

    // Overridden draw() method displaying triangle dimensions to standard output
    void draw() const override {
        // Output text description of drawing action with triangle base and height
        cout << "Drawing triangle with base " << base
             << " and height " << height << endl;
    }
};

// Entry point function of the program
int main() {
    // Declare a vector container holding unique pointers to base class Shape objects
    // Demonstrates polymorphism where heterogeneous shapes are stored in a unified collection
    vector<unique_ptr<Shape>> shapes;

    // Allocate Circle object dynamically using make_unique and append pointer to shapes vector
    shapes.push_back(make_unique<Circle>(5.0));

    // Allocate Rectangle object dynamically using make_unique and append pointer to shapes vector
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    // Allocate Triangle object dynamically using make_unique and append pointer to shapes vector
    shapes.push_back(make_unique<Triangle>(3.0, 8.0));

    // Display system banner to standard output
    cout << "=== CAD Shape System ===" << endl;

    // Range-based for loop iterating over const reference smart pointers in shapes vector
    for (const auto& shape : shapes) {
        // Call polymorphic draw() function via pointer; dynamically dispatches to derived version
        shape->draw();

        // Call polymorphic area() function via pointer and output calculated area
        cout << "Area: " << shape->area() << " square units" << endl;
    }

    // Return status 0 indicating successful execution of main function
    return 0;
}
