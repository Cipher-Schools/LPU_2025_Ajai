// Problem Statement

// Akil is attending a special event and has a unique ticket that allows him to move to the front of the line. To make use of this privilege, Akil decides to insert himself at the beginning of the line.

// Write a program that helps Akil achieve this using the array insertion concept.

// Input format :
// The first line of input is an integer N representing the current size of the line.

// The second line of input consists of N space-separated integers Positions[i], representing the current positions of the people in the line.

// The third line of input is an integer M representing Akil's unique ticket number.

// Output format :
// The output displays a single line containing N+1 space-separated integers representing the updated positions in the line after Akil inserts himself at the front.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases will fall under the following constraints:

// 2 ≤ N ≤ 10

// 1 ≤ Positions[i] ≤ 100

// 1 ≤ M ≤ 100

// Max_Size = 100

// Sample test cases :
// Input 1 :
// 2
// 1 5 
// 6
// Output 1 :
// 6 1 5 
// Input 2 :
// 5
// 45 67 34 21 12
// 89
// Output 2 :
// 89 45 67 34 21 12 
// Input 3 :
// 10
// 1 4 5 6 7 98 76 56 89 100
// 90
// Output 3 :
// 90 1 4 5 6 7 98 76 56 89 100 


#include <iostream>
using namespace std;

int main() {
    int N, M;
    int Positions[101]; // Max size = 100 + 1 for Akil

    // Input the current size of the line
    cin >> N;

    // Input the current positions
    for (int i = 0; i < N; i++) {
        cin >> Positions[i];
    }

    // Input Akil's unique ticket number
    cin >> M;

    // Shift all elements one position to the right
    for (int i = N; i > 0; i--) {
        Positions[i] = Positions[i - 1];
    }

    // Insert Akil's ticket number at the front
    Positions[0] = M;

    // Output the updated positions
    for (int i = 0; i <= N; i++) {
        cout << Positions[i] << " ";
    }

    return 0;
}
