// Static vs Non-Static Data Members

#include <iostream>
using namespace std;


class Student {
public:
    int rollNo;           // Non-static
    static int count;     // Static

    Student(int r) {
        rollNo = r;
        count++;
    }

    void show() {
        cout << "Roll No: " << rollNo << ", Total Students: " << count << endl;
    }
};

int Student::count = 0;

int main() {
    Student s1(101), s2(102), s3(103);
    s1.show();
    s2.show();
    s3.show();
    return 0;
}
