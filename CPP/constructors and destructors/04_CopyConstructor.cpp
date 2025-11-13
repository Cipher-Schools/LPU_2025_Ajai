#include <iostream>
using namespace std;

class Student {
    string name;
    int marks;
public:
    Student(string n, int m) {
        name = n;
        marks = m;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        marks = s.marks;
    }

    void display() {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s1("Ajai", 95);
    Student s2 = s1; // Copy constructor invoked
    s2.display();
}
