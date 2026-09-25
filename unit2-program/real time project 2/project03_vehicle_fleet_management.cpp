// ============================================================================
// File: project03_vehicle_fleet_management.cpp
// Unit II: Inheritance - Real-Time Application 3
// Title: Vehicle Fleet Management System
// Description: Manages logistics fleet vehicles (Truck, Delivery Van, Bike) using
//              hierarchical inheritance, protected member access, function overriding,
//              virtual functions, smart pointers, and RAII resource management.
// ============================================================================

#include <iostream>     // Include standard stream library for console output operations (std::cout)
#include <memory>       // Include memory library for modern smart pointers (std::unique_ptr, std::make_unique)
#include <string>       // Include string header for std::string type representation
#include <string_view>  // Include string_view header for lightweight string passing without string allocation
#include <vector>       // Include vector library for sequence container holding fleet vehicle pointers

// Base Class 'Vehicle' representing shared attributes and behaviors across logistics vehicles
class Vehicle {
protected:
    std::string vehicleId;          // Unique identifier code string for the vehicle (accessible by derived classes)
    std::string registrationNumber; // Official state license registration number string (accessible by derived classes)
    double fuelLevel;               // Current fuel tank level percentage (accessible by derived classes)

public:
    // Parameterized Constructor: initializes vehicle ID, registration number, and sets initial fuel level to 100%
    Vehicle(std::string_view vid, std::string_view reg)
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {} // Member initializer list

    // Start engine operation function: prints vehicle start notification
    void startEngine() const {
        std::cout << "Vehicle " << vehicleId << " engine started." << '\n'; // Print vehicle engine start message
    }

    // Refuel operation function: increases fuel level by given amount up to maximum 100% cap
    void refuel(double amount) {
        fuelLevel += amount;      // Add refuel amount to existing fuel level
        if (fuelLevel > 100.0) {  // Check if total fuel level exceeds maximum capacity limit of 100%
            fuelLevel = 100.0;    // Clamp fuel level at maximum limit of 100.0%
        }
    }

    // Virtual Function: prints common vehicle identification and state details
    virtual void displayInfo() const {
        std::cout << "Vehicle ID: " << vehicleId                       // Output vehicle ID string
                  << " | Registration: " << registrationNumber          // Output registration plate number
                  << " | Fuel: " << fuelLevel << "%" << '\n';           // Output fuel percentage with newline
    }

    // Virtual Destructor: guarantees clean destruction of derived classes via base pointers
    virtual ~Vehicle() = default;
};

// Derived Class 'Truck': inherits publicly from base class 'Vehicle'
class Truck : public Vehicle {
private:
    double cargoCapacity; // Private heavy cargo payload capacity attribute in tonnes

public:
    // Parameterized Constructor: chains to Vehicle base constructor and initializes cargo capacity
    Truck(std::string_view vid, std::string_view reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {} // Execute initializer list

    // Override displayInfo to prepend vehicle type label and append cargo capacity details
    void displayInfo() const override {
        std::cout << "Truck | ";                               // Print specific vehicle type prefix label
        Vehicle::displayInfo();                                // Call base class displayInfo to print common details
        std::cout << "Cargo capacity: " << cargoCapacity       // Print cargo weight capacity value
                  << " tonnes" << '\n';                        // Print unit suffix and newline
    }
};

// Derived Class 'DeliveryVan': inherits publicly from base class 'Vehicle'
class DeliveryVan : public Vehicle {
private:
    int packageCount; // Private package load count attribute representing loaded items

public:
    // Parameterized Constructor: chains to Vehicle base constructor and initializes package count
    DeliveryVan(std::string_view vid, std::string_view reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {} // Execute initializer list

    // Override displayInfo to prepend vehicle type label and append loaded package count details
    void displayInfo() const override {
        std::cout << "Delivery Van | ";                        // Print specific vehicle type prefix label
        Vehicle::displayInfo();                                // Call base class displayInfo to print common details
        std::cout << "Packages loaded: " << packageCount       // Print count of packages currently loaded
                  << '\n';                                     // Print newline separator
    }
};

// Derived Class 'Bike': inherits publicly from base class 'Vehicle'
class Bike : public Vehicle {
private:
    bool hasDeliveryBox; // Private boolean flag indicating presence of insulated delivery cargo box

public:
    // Parameterized Constructor: chains to Vehicle base constructor and initializes delivery box flag
    Bike(std::string_view vid, std::string_view reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {} // Execute initializer list

    // Override displayInfo to prepend vehicle type label and append delivery box availability status
    void displayInfo() const override {
        std::cout << "Delivery Bike | ";                       // Print specific vehicle type prefix label
        Vehicle::displayInfo();                                // Call base class displayInfo to print common details
        std::cout << "Delivery box: "                          // Print delivery box feature status label
                  << (hasDeliveryBox ? "Available" : "Not available") // Ternary operation for human-readable string
                  << '\n';                                     // Print newline separator
    }
};

// Main execution function
int main() {
    // Declare dynamic vector array container to store smart unique pointers pointing to Vehicle base objects
    std::vector<std::unique_ptr<Vehicle>> fleet;

    // Allocate and store a Truck object pointer with ID "V001", reg "MH12-AB-1234", capacity 10.5 tonnes
    fleet.push_back(std::make_unique<Truck>("V001", "MH12-AB-1234", 10.5));

    // Allocate and store a DeliveryVan object pointer with ID "V002", reg "MH12-CD-5678", 50 packages
    fleet.push_back(std::make_unique<DeliveryVan>("V002", "MH12-CD-5678", 50));

    // Allocate and store a Bike object pointer with ID "V003", reg "MH12-EF-9012", delivery box true
    fleet.push_back(std::make_unique<Bike>("V003", "MH12-EF-9012", true));

    // Print section header banner for fleet status report
    std::cout << "=== Fleet Status ===" << '\n';

    // Iterate polymorphically through fleet collection using const reference range-based loop
    for (const auto& vehicle : fleet) {
        vehicle->startEngine(); // Start engine for current vehicle object
        vehicle->displayInfo(); // Display full vehicle information polymorphically
        std::cout << '\n';      // Print empty line separator between fleet vehicle reports
    }

    // Return status code 0 indicating successful completion of program
    return 0;
}
