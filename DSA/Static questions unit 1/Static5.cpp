// Problem Statement

// The cable management team wants to sort the TV channels based on audience viewing times in ascending order. Implement a program that takes the number of TV channels and their respective viewing times as input, sorts the viewing times using the bubble sort technique, and then displays the sorted viewing times.

// Input format :
// The first line of input contains an integer N, representing the number of TV channels.

// The second line consists of N space-separated integers, representing the viewing time of a TV channel.

// Output format :
// The output prints a single line containing the sorted viewing times of the TV channels, separated by spaces.

// ﻿Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 2 ≤ N ≤ 20

// 1 ≤ viewing time ≤ 360

// Sample test cases :
// Input 1 :
// 6
// 23 45 68 12 57 13
// Output 1 :
// 12 13 23 45 57 68 
// Input 2 :
// 4
// 45 35 75 15
// Output 2 :
// 15 35 45 75

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // number of TV channels

    int arr[20]; // maximum as per constraint
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // viewing times
    }

    // Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print sorted viewing times
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
