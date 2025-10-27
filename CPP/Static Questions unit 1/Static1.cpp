// Problem Statement

// Hari, a fitness enthusiast, tracks the progress of participants in his fitness program. Your task is to create a program to calculate the total weight loss for a group of participants based on their workout durations.

// Use an array of Participant objects to collect details such as names, initial weights, and workout durations. Compute the weight loss for each participant and display the total weight loss for all participants combined.

// The formula for weight loss is calculated as follows:

// Weight Loss =Workout Duration / 60.0

// Input format :
// The first line of input is an integer n, representing the number of participants.

// The next n lines each contain:

// A string name, representing the participant's name.
// A double weight, representing the participant's weight.
// A double workoutDuration, representing the participant's workout duration in minutes.
// Output format :
// The output consists of a single line showing the total weight loss, formatted to two decimal places.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 9

// 1 ≤ length_of_name ≤ 20

// 1.0 ≤ weight ≤ 120.0

// 30.0 ≤ workoutDuration ≤ 600.0

// Sample test cases :
// Input 1 :
// 1
// John 80.2 60.5
// Output 1 :
// 1.01
// Input 2 :
// 5
// Nancy 70.1 270.0
// Oliver 80.2 300.1
// Patty 90.1 330.0
// Quentin 100.0 360.2
// Rachel 110.0 390 .1
// Output 2 :
// 27.50


#include <iostream>
#include <iomanip>
using namespace std;

class Participant {
public:
    string name;
    double weight;
    double workoutDuration;

    double calculateWeightLoss() {
        return workoutDuration / 60.0;
    }
};

int main() {
    int n;
    cin >> n;

    Participant participants[10];
    double totalWeightLoss = 0.0;

    for (int i = 0; i < n; i++) {
        cin >> participants[i].name >> participants[i].weight >> participants[i].workoutDuration;
        totalWeightLoss += participants[i].calculateWeightLoss();
    }

    cout << fixed << setprecision(2) << totalWeightLoss;

    return 0;
}
