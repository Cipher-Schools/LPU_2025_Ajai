#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------
// CLASS DEFINITION
//-------------------------------------------
class Student {
private:
    string name;
    int rollNo;
    float marks;

    static int studentCount; // Static member to count objects

public:
    //-------------------------------------------
    // Inline Function Example
    //-------------------------------------------
    inline float getMarks() {
        return marks;
    }

    //-------------------------------------------
    // Function Overloading Example
    //-------------------------------------------
    void setDetails(string n, int r) {
        name = n;
        rollNo = r;
        marks = 0.0;
        studentCount++;
    }

    void setDetails(string n, int r, float m) {
        name = n;
        rollNo = r;
        marks = m;
        studentCount++;
    }

    //-------------------------------------------
    // Static Function Example
    //-------------------------------------------
    static int getStudentCount() {
        return studentCount;
    }

    //-------------------------------------------
    // Display Details
    //-------------------------------------------
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }

    //-------------------------------------------
    // Compare Two Students (Pass & Return Object)
    //-------------------------------------------
    Student compareMarks(Student other) {
        if (marks > other.marks)
            return *this;
        else
            return other;
    }
};

// Initialize static member
int Student::studentCount = 0;

//-------------------------------------------
// MAIN FUNCTION
//-------------------------------------------
int main() {
    cout << "=== Demonstrating Classes & Objects in C++ ===" << endl;

    // Create objects without constructor
    Student s1, s2, s3;

    // Set details using function overloading
    s1.setDetails("Ravi", 101, 87.5);
    s2.setDetails("Nandhini", 102, 92.0);
    s3.setDetails("Ajay", 103); // marks = 0.0 by default

    // Display all students
    cout << "\n--- Student Details ---" << endl;
    s1.display();
    s2.display();
    s3.display();

    // Compare students and get topper
    Student topper = s1.compareMarks(s2);
    cout << "\nTopper based on marks:" << endl;
    topper.display();

    // Array of objects
    cout << "\n--- Array of Students ---" << endl;
    Student arr[2];
    arr[0].setDetails("Divya", 104, 78.5);
    arr[1].setDetails("Vasu", 105, 88.0);

    for (int i = 0; i < 2; i++) {
        arr[i].display();
    }

    // Display total number of Student objects created
    cout << "\nTotal Students Created: " << Student::getStudentCount() << endl;

    return 0;
}
