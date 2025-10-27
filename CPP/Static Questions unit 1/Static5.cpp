#include <iostream>
#include <iomanip>
using namespace std;

struct Circle {
    double radius;
};

int main() {
    Circle c;

    cin >> c.radius;

    double area = 3.14 * c.radius * c.radius;

    cout << fixed << setprecision(2) << area;

    return 0;
}


// Problem Statement

// John is studying geometry and wants to calculate the area of a circle. He needs your help to create a C++ program that takes the radius of the circle as input and calculates its area using pointers to structures.

// The program contains a structure called Circle that holds the radius value as an attribute.
TH
// Formula: Area of a circle = 3.14 * radius * radius

// Input format :
// The input consists of a double-point number (r) representing the radius of the circle.

// Output format :
// The output displays a double-point number representing the area of the circle, rounded off to two decimal places.

// Code constraints :
// 0.00 < r < 101.00

// Sample test cases :
// Input 1 :
// 4.25
// Output 1 :
// 56.72
// Input 2 :
// 2.76
// Output 2 :
// 23.92