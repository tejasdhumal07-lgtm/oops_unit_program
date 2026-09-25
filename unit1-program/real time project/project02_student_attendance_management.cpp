// Include standard input-output stream library for console operations
#include <iostream>
// Include string library to manage textual data such as student names
#include <string>

// Define Student class to manage student roll number, name, and attendance records
class Student {
// Private data members enforcing encapsulation and data abstraction
private:
    // Integer variable to store unique student roll number
    int rollNo;
    // String variable to store student full name
    std::string name;
    // Integer variable to track total number of conducted classes/days
    int totalDays;
    // Integer variable to track number of days student was present
    int presentDays;

// Public member functions defining operations on Student objects
public:
    // Parameterized constructor initializing roll number and name, setting day counters to 0
    Student(int r, const std::string& n)
        // Initialize rollNo with r, name with n, totalDays with 0, presentDays with 0
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    // Member function to record attendance for a single day based on presence flag
    void markAttendance(bool isPresent) {
        // Increment total conducted days count by 1
        totalDays++;
        // Check if student was present on this day
        if (isPresent) {
            // Increment present days count by 1
            presentDays++;
        }
    }

    // Const member function calculating and returning attendance percentage
    double getAttendancePercentage() const {
        // Handle edge case where no classes have been conducted yet
        if (totalDays == 0) {
            // Return 0.0 percentage when total days is 0 to avoid division by zero
            return 0.0;
        }
        // Calculate and return attendance percentage formula: (presentDays * 100.0) / totalDays
        return (presentDays * 100.0) / totalDays;
    }

    // Const member function displaying student roll number, name, and attendance percentage
    void display() const {
        // Format and output student details and percentage to standard console
        std::cout << "Roll: " << rollNo
                  << " | Name: " << name
                  << " | Attendance: " << getAttendancePercentage() << "%" << std::endl;
    }
};

// Execution entry point of the application
int main() {
    // Instantiate Student object s1 with roll number 101 and name "Rahul"
    Student s1(101, "Rahul");
    // Instantiate Student object s2 with roll number 102 and name "Priya"
    Student s2(102, "Priya");

    // Mark student s1 present for day 1
    s1.markAttendance(true);
    // Mark student s1 present for day 2
    s1.markAttendance(true);
    // Mark student s1 absent for day 3
    s1.markAttendance(false);

    // Mark student s2 present for day 1
    s2.markAttendance(true);
    // Mark student s2 present for day 2
    s2.markAttendance(true);
    // Mark student s2 present for day 3
    s2.markAttendance(true);

    // Output title header for attendance report
    std::cout << "=== Attendance Report ===" << std::endl;

    // Display attendance details for student s1
    s1.display();
    // Display attendance details for student s2
    s2.display();

    // Return 0 indicating successful execution of main
    return 0;
}
