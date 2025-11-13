#include <iostream>
using namespace std;

class Employee {
    string name;
    int salary;

public:
    Employee(string n, int s) { // Parameterized Constructor
        name = n;
        salary = s;
    }

    void display() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

int main() {
    Employee e1("Ava", 50000);
    Employee e2("Ram", 60000);
    e1.display();
    e2.display();
}
