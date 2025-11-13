#include <iostream>
using namespace std;

class Student {
public:
    Student() {  // Constructor
        cout << "Constructor called - Object Created!" << endl;
    }
};

int main() {
    Student s1, s2; // Constructor called twice
    return 0;
}
