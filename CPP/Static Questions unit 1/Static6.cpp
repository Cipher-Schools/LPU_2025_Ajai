#include <iostream>
using namespace std;

class Triangle {
    double s1, s2, s3;

public:
    void getSides(double a, double b, double c) {
        s1 = a;
        s2 = b;
        s3 = c;
    }

    // Friend function declaration
    friend void findType(Triangle t);
};

// Friend function definition
void findType(Triangle t) {
    if (t.s1 == t.s2 && t.s2 == t.s3)
        cout << "Equilateral triangle";
    else if (t.s1 == t.s2 || t.s2 == t.s3 || t.s1 == t.s3)
        cout << "Isosceles triangle";
    else
        cout << "Scalene triangle";
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    Triangle t;
    t.getSides(a, b, c);

    findType(t);

    return 0;
}


// Problem Statement

// Arjun is learning about triangles in his geometry class. He wants to write a program that takes the lengths of the three sides of a triangle and tells if it is Equilateral, Isosceles, or Scalene. If all three sides are the same length, the triangle is Equilateral. If only two sides are the same, it is Isosceles. If all sides are different lengths, it is Scalene. 

// Help him to implement this using a friend function.

// Input format :
// The input consists of double-point numbers s1, s2, and s3, where s1, s2, and s3 represent the lengths of the three sides of a triangle separated by a space.

// Output format :
// The output displays one of the following messages:

// "Equilateral triangle" if all three sides are of equal length.

// "Isosceles triangle" if at least two sides are of equal length.

// "Scalene triangle" if none of the sides are of equal length.

// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 0.0 < s1, s2, s3 ≤ 10.0

// Sample test cases :
// Input 1 :
// 5.0 5.0 5.0
// Output 1 :
// Equilateral triangle
// Input 2 :
// 4.0 2.0 4.0
// Output 2 :
// Isosceles triangle
// Input 3 :
// 4.7 6.8 3.4
// Output 3 :
// Scalene triangle