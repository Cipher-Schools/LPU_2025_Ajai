// Problem Statement

// Vasu needs to find the position of the second occurrence of a specific number in a list using linear search. 

// Write a program that reads the list of numbers and a key, and outputs the index of the second occurrence of the key or a message if the key is not found or found less than twice.

// Input format :
// The first line of input consists of an integer n, representing the number of elements.

// The second line consists of the n space-separated integers, representing the elements.

// The third line consists of an integer k, representing the key value to be searched.

// Output format :
// The output prints the index(0-based) of the second occurrence of the key value in the array.

// If the key value is not found or is found only once in the array, print "Key not found or found only once".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases fall under the following specifications:

// 1 ≤ n ≤ 10

// 1 ≤ elements, k ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 5 6 2
// 2
// Output 1 :
// 4
// Input 2 :
// 4
// 1 2 3 4
// 8
// Output 2 :
// Key not found or found only on

#include <iostream>
using namespace std;

int main() {
    int n, k;
    int arr[10]; // Maximum 10 elements as per constraints
    
    // Input number of elements
    cin >> n;

    // Input elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input key to be searched
    cin >> k;

    int count = 0;  // To count occurrences of key
    int index = -1; // To store index of second occurrence

    // Linear search to find second occurrence
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            count++;
            if (count == 2) {
                index = i;
                break;
            }
        }
    }

    // Output result
    if (index != -1)
        cout << index;
    else
        cout << "Key not found or found only once";

    return 0;
}
