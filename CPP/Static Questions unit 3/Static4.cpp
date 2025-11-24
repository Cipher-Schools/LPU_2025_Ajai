#include <iostream>
#include <iomanip>
using namespace std;

class Student {
public:
    int roll;
    string name;
    double fee;

    // Parameterized constructor
    Student(int r, string n, double f) {
        roll = r;
        name = n;
        fee = f;
    }

    // Copy constructor
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
        fee = s.fee;
    }
};

int main() {
    int roll;
    string name;
    double fee;

    cin >> roll;
    cin >> name;
    cin >> fee;

    Student s1(roll, name, fee);   // original object
    Student s2(s1);                // copied object

    cout << "Student Details:" << endl;
    cout << s1.roll << " " << s1.name << " " 
         << fixed << setprecision(2) << s1.fee << endl;

    cout << "Copied Student Details:" << endl;
    cout << s2.roll << " " << s2.name << " " 
         << fixed << setprecision(2) << s2.fee;

    return 0;
}


// Problem Statement

// Fathima, a teacher, needs a program to manage student details for her class. 
// The program should store and display the student's roll number, name, and fee. 
// Additionally, it should demonstrate the use of a copy constructor to create a duplicate 
// of the student's details and display both the original and copied student information.

// Input format :
// The first line of input consists of an integer roll number, the string name, and 
// the double fee of the student (as a double-point value) , each on separate lines.

// Output format :
// The output format is as follows:

// After entering the student details, the output displays "Student Details:" on the first line.

// The student's roll number, name, and fee are then displayed on the same line, separated by a space.

// After that, the program displays "Copied Student Details:" on a new line.

// The copied student details are then displayed on the same line, separated by a space.



// Refer to the sample output for the exact format.

// Code constraints :
// 0 < roll number, fee

// The fee value is rounded off to two decimal places.

// Sample test cases :
// Input 1 :
// 101
// John
// 30500.55
// Output 1 :
// Student Details:
// 101 John 30500.55
// Copied Student Details:
// 101 John 30500.55
// Input 2 :
// 26
// Preethi
// 25000.50
// Output 2 :
// Student Details:
// 26 Preethi 25000.50
// Copied Student Details:
// 26 Preethi 25000.50