// Include standard input-output stream library for console output operations
#include <iostream>
// Include string library for device attributes like ID, type, location, status, timestamp
#include <string>
// Include vector library for managing collection of smart devices dynamically
#include <vector>

// Define SmartDevice class representing an IoT device in a smart home system
class SmartDevice {
// Private section encapsulating device attributes
private:
    // Unique device identifier string (e.g., D101)
    std::string deviceId;
    // Type of smart device (e.g., Light, Thermostat, Camera, Door Lock)
    std::string deviceType;
    // Location of device in house (e.g., Living Room, Bedroom)
    std::string location;
    // Current operational state (e.g., ON, OFF, LOCKED, UNLOCKED)
    std::string status;
    // Timestamp indicating when state was last modified
    std::string lastUpdated;

// Public section declaring constructors and interaction methods
public:
    // Parameterized constructor initializing smart device data members
    SmartDevice(const std::string& id, const std::string& type, const std::string& loc, const std::string& stat, const std::string& time)
        // Initialize deviceId, deviceType, location, status, and lastUpdated using initializer list
        : deviceId(id), deviceType(type), location(loc), status(stat), lastUpdated(time) {}

    // Inline accessor function returning device ID
    inline std::string getDeviceId() const { return deviceId; }
    // Inline accessor function returning device type
    inline std::string getDeviceType() const { return deviceType; }
    // Inline accessor function returning location
    inline std::string getLocation() const { return location; }
    // Inline accessor function returning current status
    inline std::string getStatus() const { return status; }

    // Member function to update device operational status and timestamp
    void updateStatus(const std::string& newStatus, const std::string& newTime) {
        // Assign new state string to private status variable
        status = newStatus;
        // Assign new time string to private lastUpdated variable
        lastUpdated = newTime;
    }

    // Const member function displaying device details in formatted string
    void displayDevice() const {
        // Output device ID, type, location, status, and last updated timestamp
        std::cout << "ID: " << deviceId
                  << " | Type: " << deviceType
                  << " | Location: " << location
                  << " | Status: " << status
                  << " | Last Updated: " << lastUpdated << std::endl;
    }
};

// Define SmartHomeManager class to maintain home dashboard and device collection
class SmartHomeManager {
// Private vector container holding all registered smart devices
private:
    // Vector of SmartDevice objects representing home network devices
    std::vector<SmartDevice> devices;

// Public methods for managing smart home ecosystem
public:
    // Member function to add a new device to the smart home network
    void addDevice(const SmartDevice& device) {
        // Append passed device object to private devices vector
        devices.push_back(device);
    }

    // Member function to control/update status of a specific device by ID
    void controlDevice(const std::string& id, const std::string& newStatus, const std::string& time) {
        // Iterate through devices vector using range-based reference loop
        for (auto& dev : devices) {
            // Check if current device ID matches target device ID
            if (dev.getDeviceId() == id) {
                // Update device status and timestamp
                dev.updateStatus(newStatus, time);
                // Print confirmation log message for successful update
                std::cout << "--> Device " << id << " (" << dev.getDeviceType() << ") status updated to '" << newStatus << "' at " << time << std::endl;
                // Exit function after finding and updating device
                return;
            }
        }
        // Print warning if device ID was not found in home network
        std::cout << "--> Device " << id << " not found!" << std::endl;
    }

    // Const member function displaying overall smart home dashboard
    void displayDashboard() const {
        // Output dashboard section header title
        std::cout << "=== Smart Home Device Manager Dashboard ===" << std::endl;
        // Iterate through all smart devices in system
        for (const auto& dev : devices) {
            // Display device parameters
            dev.displayDevice();
        }
    }
};

// Main function executing smart home simulation scenario
int main() {
    // Instantiate SmartHomeManager object to manage home network
    SmartHomeManager home;

    // Add smart light in Living Room initially OFF at 08:00 AM
    home.addDevice(SmartDevice("D101", "Smart Light", "Living Room", "OFF", "08:00 AM"));
    // Add smart thermostat in Bedroom initially 24 deg C at 08:00 AM
    home.addDevice(SmartDevice("D102", "Thermostat", "Bedroom", "24 deg C", "08:00 AM"));
    // Add security camera at Front Door initially ACTIVE at 08:00 AM
    home.addDevice(SmartDevice("D103", "Security Camera", "Front Door", "ACTIVE", "08:00 AM"));
    // Add smart lock at Main Entrance initially LOCKED at 08:00 AM
    home.addDevice(SmartDevice("D104", "Door Lock", "Main Entrance", "LOCKED", "08:00 AM"));

    // Display initial home status dashboard
    home.displayDashboard();

    // Print status change operations header
    std::cout << "\n=== Device Operations ===" << std::endl;
    // Switch Smart Light D101 ON at 08:15 AM
    home.controlDevice("D101", "ON", "08:15 AM");
    // Adjust Thermostat D102 temperature setting to 21 deg C at 08:20 AM
    home.controlDevice("D102", "21 deg C", "08:20 AM");
    // Unlock Door Lock D104 for user access at 08:25 AM
    home.controlDevice("D104", "UNLOCKED", "08:25 AM");

    // Output spacing line before dashboard refresh
    std::cout << std::endl;

    // Display updated smart home dashboard showing reflect changes
    home.displayDashboard();

    // Return 0 indicating successful execution
    return 0;
}
