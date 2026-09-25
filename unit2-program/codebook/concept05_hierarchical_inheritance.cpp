// Header for input/output operations
#include <iostream>
// Header for standard string manipulation
#include <string>
// Header for std::move semantics
#include <utility>

// Base class Vehicle
class Vehicle {
protected:
    // Protected member variable for storing vehicle registration number
    std::string registrationNumber;

public:
    // Constructor for Vehicle class
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}

    // Method to display starting message of vehicle
    void start() const {
        // Output start status with registration number
        std::cout << "Vehicle " << registrationNumber << " started\n";
    }
};

// Derived class Car inheriting from Vehicle
class Car : public Vehicle {
public:
    // Constructor for Car initializing base Vehicle class
    explicit Car(std::string registration) : Vehicle(std::move(registration)) {}

    // Specific method for Car class
    void openBoot() const {
        // Output car boot status message
        std::cout << "Car boot opened\n";
    }
};

// Derived class Bike inheriting from Vehicle
class Bike : public Vehicle {
public:
    // Constructor for Bike initializing base Vehicle class
    explicit Bike(std::string registration) : Vehicle(std::move(registration)) {}

    // Specific method for Bike class
    void helmetReminder() const {
        // Output helmet reminder message
        std::cout << "Please wear a helmet\n";
    }
};

// Main execution block
int main() {
    // Instantiate Car object with registration number
    Car car("MH12AB1234");
    // Instantiate Bike object with registration number
    Bike bike("MH12CD5678");

    // Call start method inherited from Vehicle for car
    car.start();
    // Call openBoot method specific to Car
    car.openBoot();

    // Call start method inherited from Vehicle for bike
    bike.start();
    // Call helmetReminder method specific to Bike
    bike.helmetReminder();

    // End program with exit code 0
    return 0;
}
