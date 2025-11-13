#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;
public:
    Rectangle() { // Default Constructor
        length = 1;
        breadth = 1;
    }

    void area() {
        cout << "Area = " << length * breadth << endl;
    }
};

int main() {
    Rectangle r1; // Default constructor invoked
    r1.area();
}
