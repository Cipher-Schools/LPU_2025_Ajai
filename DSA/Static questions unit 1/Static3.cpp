// Problem Statement

// Rajini is a student who loves coding. He is working on an array operations problem. In the given problem, Rajini needs to remove the first element from the array and print the modified array.


// Help Rajini write a program that takes an array of integers as input, deletes the first element from the array, and prints the modified array.

// Input format :
// The first line of input is an integer n, representing the number of elements in the array.

// The second line of input consists of n space-separated integers, representing the elements of the array arr[i].

// Output format :
// The output displays n space-separated integers of the modified array after deleting the first element.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases will fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ arr[i] ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 6 7 4 3 1
// Output 1 :
// 7 4 3 1 
// Input 2 :
// 2
// 10 47
// Output 2 :
// 47 
// Input 3 :
// 10
// 37 84 27 23 48 19 1 38 27 39
// Output 3 :
// 84 27 23 48 19 1 38 27 39 


#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[10]; // Maximum size = 10

    // Input number of elements
    cin >> n;

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Remove first element by shifting all elements to the left
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Output modified array
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
