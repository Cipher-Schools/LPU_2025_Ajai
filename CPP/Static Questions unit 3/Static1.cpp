#include <iostream>
using namespace std;

class Parallelogram {
public:
    int base;
    int height;

    // Default constructor
    Parallelogram() {
        base = 0;
        height = 0;
    }

    // Method to calculate area
    int area() {
        return base * height;
    }
};

int main() { 
    Parallelogram p;
    cin >> p.base >> p.height;
    cout << p.area() << " sq.units";
    return 0;
}


// Problem Statement



// Alice wants to calculate the area of a parallelogram for her geometry homework. 
// She measures the base and height of the parallelogram and uses a program to input these 
// values and calculate the area in square units. 



// Help her with a program using the following approach.



// Create a class called Parallelogram that has base and height as public attributes. 
// Use a default constructor to initialize both values to 0. Now using a method called area(), 
// calculate the area of the parallelogram.



// Formula: Area of a Parallelogram = base * height

// Input format :
// The input consists of two space-separated integers: the base and height values of the parallelogram.

// Output format :
// The output displays an integer representing the area of the parallelogram, followed by " sq.units".



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ base, height ≤ 100

// Sample test cases :
// Input 1 :
// 15 20 
// Output 1 :
// 300 sq.units
// Input 2 :
// 4 6
// Output 2 :
// 24 sq.units