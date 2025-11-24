#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream file;
    file.open("ages.txt");   // open the file

    if (!file) {
        return 0;            // file not found handling (optional)
    }

    int N;
    file >> N;

    if (N > 20) {
        cout << "Exceeding limit!";
        file.close();        // close file
        return 0;
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        int age;
        file >> age;
        sum += age;
    }

    file.close();            // close the file

    float avg = sum / N;
    cout << fixed << setprecision(1) << avg;

    return 0;
}


// Problem Statement

// Jenifer has a text file named 'ages.txt' that contains the ages of individuals, 
// where you can enter up to 20 individual's ages as space-separated integers. 
// She needs to write a program to read this file, calculate the average age, and display it. 



// Help her with the task.

// Input format :
// The first line of input consists of an integer N, representing the total number of individuals.

// The second line consists of N space-separated positive integers, 
// each representing an individual's age.

// Output format :
// The output prints a float value, representing the average age, rounded to one decimal place.

// If N exceeds 20, the output prints "Exceeding limit!".



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 20

// Sample test cases :
// Input 1 :
// 3
// 15 16 18
// Output 1 :
// 16.3
// Input 2 :
// 4
// 50 20 30 40
// Output 2 :
// 35.0
// Input 3 :
// 21
// 71 29 69 23 43 86 63 88 54 21 14 79 59 77 33 19 52 58 61 78 46
// Output 3 :
// Exceeding limit!