// Header file for stream IO operations
#include <iostream>
// Header file for string operations
#include <string>
// Header file for std::move utility function
#include <utility>

// Base class Vehicle representing a general rental vehicle
class Vehicle {
protected:
    // Protected variable storing vehicle registration number
    std::string registrationNumber;
    // Protected variable storing daily rental rate
    double ratePerDay;

public:
    // Parameterized constructor initializing registration number and daily rate
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    // Virtual function to calculate total rental cost based on days
    virtual double calculateRent(int days) const {
        // Return base rent: rate per day multiplied by number of days
        return ratePerDay * days;
    }

    // Virtual function to display general vehicle details
    virtual void display() const {
        // Print registration number
        std::cout << "Registration: " << registrationNumber << '\n';
        // Print daily rate
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // Virtual destructor for polymorphic cleanup safety
    virtual ~Vehicle() = default;
};

// Derived class Car inheriting from Vehicle
class Car : public Vehicle {
private:
    // Private variable for car door count
    int numberOfDoors;

public:
    // Constructor calling base Vehicle constructor and setting door count
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate), numberOfDoors(doors) {}

    // Overridden display method extending base display implementation
    void display() const override {
        // Call base class display method for registration and rate
        Vehicle::display();
        // Print car door count
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

// Derived class Bike inheriting from Vehicle
class Bike : public Vehicle {
private:
    // Private variable for bike engine capacity in cc
    int engineCapacity;

public:
    // Constructor calling base Vehicle constructor and setting engine capacity
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate), engineCapacity(capacity) {}

    // Overridden rent calculation applying a 10% discount for bikes (rate * days * 0.9)
    double calculateRent(int days) const override {
        // Calculate discounted rent for bike
        return ratePerDay * days * 0.9;
    }

    // Overridden display method extending base display implementation
    void display() const override {
        // Call base class display method for registration and rate
        Vehicle::display();
        // Print engine capacity in cc
        std::cout << "Engine Capacity: " << engineCapacity << " cc\n";
    }
};

// Main function - Entry point of application
int main() {
    // Instantiate Car object with registration, daily rate, and number of doors
    Car car("MH12AB1234", 2000.0, 5);
    // Instantiate Bike object with registration, daily rate, and engine capacity
    Bike bike("MH12CD5678", 800.0, 150);

    // Print header for Car details
    std::cout << "Car Details\n";
    // Display car information
    car.display();
    // Calculate and print 3-day rental cost for car
    std::cout << "Rent for 3 days: " << car.calculateRent(3) << "\n\n";

    // Print header for Bike details
    std::cout << "Bike Details\n";
    // Display bike information
    bike.display();
    // Calculate and print 3-day rental cost for bike
    std::cout << "Rent for 3 days: " << bike.calculateRent(3) << '\n';

    // Return 0 indicating successful execution
    return 0;
}
