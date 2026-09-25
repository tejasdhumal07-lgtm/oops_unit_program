// Include standard input-output stream library for console operations
#include <iostream>
// Include string library for handling textual data like sensor IDs and timestamps
#include <string>
// Include vector container library for dynamic collection of sensor objects
#include <vector>

// Define SoilSensor class representing a physical soil moisture sensor object
class SoilSensor {
// Private section ensures data encapsulation by hiding internal variables
private:
    // Unique identifier string for each sensor (e.g., S001)
    std::string sensorId;
    // Current soil moisture content expressed as a percentage
    double moistureLevel;
    // Timestamp recording when the moisture reading was registered
    std::string timestamp;

// Public section exposes constructors and member methods for external interaction
public:
    // Parameterized constructor initializing sensor attributes via member initializer list
    SoilSensor(const std::string& id, double moisture, const std::string& time)
        // Initialize sensorId, moistureLevel, and timestamp data members
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    // Member function to update the sensor's moisture level and time of reading
    void readSensor(double newMoisture, const std::string& newTime) {
        // Update private moisture level member with new moisture value
        moistureLevel = newMoisture;
        // Update private timestamp member with new timestamp value
        timestamp = newTime;
    }

    // Const member function to display current sensor details to standard output
    void displayData() const {
        // Format and print sensor ID, moisture percentage, and timestamp to console
        std::cout << "Sensor: " << sensorId
                  << " | Moisture: " << moistureLevel << "%"
                  << " | Time: " << timestamp << std::endl;
    }
};

// Execution entry point of the C++ application
int main() {
    // Declare a vector container to store multiple SoilSensor objects
    std::vector<SoilSensor> farmSensors;

    // Construct and append the first soil sensor object S001 with moisture 45.2% at 08:00
    farmSensors.emplace_back("S001", 45.2, "08:00");
    // Construct and append the second soil sensor object S002 with moisture 52.8% at 08:00
    farmSensors.emplace_back("S002", 52.8, "08:00");
    // Construct and append the third soil sensor object S003 with moisture 38.5% at 08:00
    farmSensors.emplace_back("S003", 38.5, "08:00");

    // Display title header for initial morning sensor readings
    std::cout << "=== Morning Sensor Readings ===" << std::endl;

    // Iterate through all SoilSensor objects stored in the vector using range-based for loop
    for (const auto& sensor : farmSensors) {
        // Call displayData function on current sensor object to output readings
        sensor.displayData();
    }

    // Update the reading for sensor S001 (index 0) with new moisture 47.5% at 09:00
    farmSensors[0].readSensor(47.5, "09:00");

    // Output title header for the updated sensor reading
    std::cout << "\n=== Updated Reading ===" << std::endl;

    // Display the updated state of sensor S001 (index 0)
    farmSensors[0].displayData();

    // Return 0 indicating successful termination of the program
    return 0;
}
