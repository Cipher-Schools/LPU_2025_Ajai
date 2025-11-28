#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

class Employee {
private:
    char name[50];
    double salary;

public:
    void inputEmployee() {
        cin.ignore();
        cin.getline(name, 50);
        cin >> salary;
    }

    void writeToFile(ofstream& outfile) {
        outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    void readFromFile(ifstream& infile) {
        infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    }

    double getSalary() const {
        return salary;
    }

    const char* getName() const {
        return name;
    }
};

int main() {
    ofstream outfile;
    outfile.open("employees.bin", ios::binary);

    int n;
    cin >> n;

    if (n > 20) {
        return 0;
    }

    Employee employee;
    for (int i = 0; i < n; i++) {
        employee.inputEmployee();
        employee.writeToFile(outfile);
    }

    outfile.close();

    ifstream infile;
    infile.open("employees.bin", ios::binary);

    Employee employeeAtPosition;
    double totalSalary = 0;
    int count = 0;

    while (infile.read(reinterpret_cast<char*>(&employeeAtPosition), sizeof(Employee))) {
        totalSalary += employeeAtPosition.getSalary();
        count++;
    }

    double averageSalary = totalSalary / count;
    double discountedSalary = averageSalary * 0.90;

    cout << fixed << setprecision(2);
    cout << discountedSalary << endl;

    infile.close();
    return 0;
}