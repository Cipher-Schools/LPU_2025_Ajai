#include <iostream>
#include <iomanip>
using namespace std;

class HealthProfile {
public:
    string name;
    int age;
    double height;
    double weight;

    double calculateBMI() {
        return weight / (height * height);
    }
};

void displayProfile(HealthProfile hp) {
    cout << "BMI: " << fixed << setprecision(2) << hp.calculateBMI();
}

int main() {
    HealthProfile hp;

    getline(cin, hp.name);
    cin >> hp.age >> hp.height >> hp.weight;

    displayProfile(hp);

    return 0;
}


// Problem Statement

// Dhanush is working on a project to help individuals assess their health by calculating their Body Mass Index (BMI). He has written a program that takes basic information from users and computes their BMI. 

// The program uses a HealthProfile class to store user information and calculate BMI in the calculateBMI method. Display the result using the displayProfile method which takes the HealthProfile class's object as the argument.

// Formula: BMI = weight / height2

// Input format :
// The first line of input consists of a string, representing the user's name.

// The second line consists of an integer, representing the user's age.

// The third line consists of a double value, representing the user's height in meters.

// The fourth line consists of a double value, representing the user's weight in kilograms.

// Output format :
// The output prints "BMI: " followed by the calculated BMI, rounded off to two decimal places.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 20 ≤ age ≤ 80

// 0.1 ≤ height ≤ 3.0

// 50.0 ≤ weight ≤ 120.0

// Sample test cases :
// Input 1 :
// John Doe
// 30
// 1.75
// 70.0
// Output 1 :
// BMI: 22.86
// Input 2 :
// Arun
// 23
// 1.57
// 71.5
// Output 2 :
// BMI: 29.01