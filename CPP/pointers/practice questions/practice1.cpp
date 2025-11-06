// Create a class Rectangle with length and breadth.
// Use a pointer to object to input dimensions and display the area.
// Hint: Use ptr->length, ptr->breadth, ptr->display().


#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float breadth;

public:
    // Function to input dimensions
    void getData() {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
    }

    // Function to calculate area
    float area() {
        return length * breadth;
    }

    // Function to display area
    void display() {
        cout << "Area of Rectangle = " << area() << endl;
    }
};

int main() {
    Rectangle rect;          // Normal object
    Rectangle *ptr = &rect;  // Pointer to object

    cout << "Enter rectangle details:\n";
    ptr->getData();          // Access using pointer
    ptr->display();          // Access using pointer

    return 0;
}
