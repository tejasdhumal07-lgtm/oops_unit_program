// Header file for stream IO operations
#include <iostream>

// Base class Vehicle demonstrating runtime polymorphism
class Vehicle {
public:
    // Virtual function move() meant to be overridden in derived classes
    virtual void move() const {
        // Default implementation output
        std::cout << "Vehicle is moving\n";
    }
    // Virtual destructor ensuring correct cleanup when deleting derived objects via base pointer
    virtual ~Vehicle() = default;
};

// Derived class Car overriding virtual function move()
class Car : public Vehicle {
public:
    // Overridden move() implementation for Car
    void move() const override {
        // Output car specific movement details
        std::cout << "Car moves on roads\n";
    }
};

// Derived class Boat overriding virtual function move()
class Boat : public Vehicle {
public:
    // Overridden move() implementation for Boat
    void move() const override {
        // Output boat specific movement details
        std::cout << "Boat moves on water\n";
    }
};

// Main function
int main() {
    // Instantiate Car object
    Car car;
    // Instantiate Boat object
    Boat boat;
    // Invoke overridden move() for Car
    car.move();
    // Invoke overridden move() for Boat
    boat.move();
    // Exit with status code 0
    return 0;
}
