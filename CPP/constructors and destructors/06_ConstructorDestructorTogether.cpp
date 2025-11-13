#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        cout << "Object created" << endl;
    }

    ~Student() {
        cout << "Object destroyed" << endl;
    }
};

int main() {
    cout << "Entering block" << endl;
    {
        Student s1;
    }
    cout << "Exiting block" << endl;
}
