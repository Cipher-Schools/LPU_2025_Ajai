#include <iostream>
using namespace std;

int sumOfEven(int m, int n) {
    if (m > n)
        return 0;
    if (m % 2 == 0)
        return m + sumOfEven(m + 1, n);
    else
        return sumOfEven(m + 1, n);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << sumOfEven(m, n);
    return 0;
}

// Problem statement

// Alice is a mathematics enthusiast and is currently studying even numbers and their sums. She's curious to know the sum of all even numbers within a given range. Can you help her by writing a program that calculates and displays the sum of even numbers between a starting and ending point?

// Write a program to calculate and display the sum of all even numbers between a given starting and ending point. The program should use a recursive function sumOfEvenOdd to achieve this. Take input from the user for the starting and ending points, and output the calculated sum with a suitable message.

// Note: Starting and ending points are included.

// Input format :
// The input consists of the lower range m and upper range n in separate lines.

// Output format :
// The output prints the sum of even numbers in the given range.

// Code constraints :
// 0 < m < n < 104

// Sample test cases :
// Input 1 :
// 2
// 6
// Output 1 :
// 12
// Input 2 :
// 50 
// 60
// Output 2 :
// 330