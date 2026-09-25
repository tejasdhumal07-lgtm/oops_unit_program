// Header for iostream console standard operations
#include <iostream>

// First base class Academic
class Academic {
protected:
    // Protected member variable for academic marks
    int academicMarks;

public:
    // Parameterized constructor initializing academic marks
    explicit Academic(int marks) : academicMarks(marks) {}

    // Member function to display academic marks
    void showAcademic() const {
        // Output academic marks to console
        std::cout << "Academic Marks: " << academicMarks << '\n';
    }
};

// Second base class Sports
class Sports {
protected:
    // Protected member variable for sports marks
    int sportsMarks;

public:
    // Parameterized constructor initializing sports marks
    explicit Sports(int marks) : sportsMarks(marks) {}

    // Member function to display sports marks
    void showSports() const {
        // Output sports marks to console
        std::cout << "Sports Marks: " << sportsMarks << '\n';
    }
};

// Derived class Student inheriting from both Academic and Sports base classes
class Student : public Academic, public Sports {
public:
    // Constructor calling both Academic and Sports base class constructors
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {}

    // Function to calculate and output combined total marks
    void showTotal() const {
        // Output sum of academicMarks and sportsMarks
        std::cout << "Total Marks: " << academicMarks + sportsMarks << '\n';
    }
};

// Main function
int main() {
    // Instantiate Student object with 80 academic marks and 15 sports marks
    Student student(80, 15);
    // Display academic marks
    student.showAcademic();
    // Display sports marks
    student.showSports();
    // Display total combined marks
    student.showTotal();
    // Return 0 for success
    return 0;
}
