#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> // For std::numeric_limits

// Custom manipulator to format currency
std::ostream& currency(std::ostream& os) {
    os << std::fixed << std::setprecision(2) << "₹";
    return os;
}

class Student {
private:
    std::string name;
    int marks;
    double tuitionFee;

public:
    // Constructor to initialize student data
    Student(const std::string& n, int m, double fee)
        : name(n), marks(m), tuitionFee(fee) {}

    // Getters
    std::string getName() const { return name; }
    int getMarks() const { return marks; }
    double getTuitionFee() const { return tuitionFee; }
};

// Function to display student data with formatting
void displayStudentData(const std::vector<Student>& students) {
    std::cout << std::left << std::setw(20) << "Student Name"
              << std::setw(10) << "Marks"
              << std::setw(15) << "Tuition Fee" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    for (const auto& student : students) {
        std::cout << std::left << std::setw(20) << student.getName()
                  << std::setw(10) << student.getMarks()
                  << currency << student.getTuitionFee() << std::endl;
    }
}

int main() {
    std::vector<Student> students;
    int numStudents;

    // Input number of students with validation
    std::cout << "Enter the number of students: ";
    while (!(std::cin >> numStudents) || numStudents <= 0) {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a positive integer for the number of students: ";
    }

    // Input student data
    for (int i = 0; i < numStudents; ++i) {
        std::string name;
        int marks;
        double tuitionFee;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        std::cout << "Enter name of student #" << i + 1 << ": ";
        std::getline(std::cin, name); // Allow spaces in the name

        // Input marks with validation
        std::cout << "Enter marks for " << name << ": ";
        while (!(std::cin >> marks) || marks < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a non-negative integer for marks: ";
        }

        // Input tuition fee with validation
        std::cout << "Enter tuition fee for " << name << ": ₹";
        while (!(std::cin >> tuitionFee) || tuitionFee < 0.0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a non-negative number for tuition fee: ₹";
        }

        // Create Student object and add it to the vector
        students.emplace_back(name, marks, tuitionFee);
    }

    // Display the formatted student data
    displayStudentData(students);

    std::cout<<"HARSH_HIRPARA_24CE040";
    return 0;
}
