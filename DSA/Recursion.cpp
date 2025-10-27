#include <iostream>
using namespace std;

// Function to calculate factorial recursively

int factorial(int n) {
    if (n == 0)  // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive case
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << num << " = " << factorial(num) << endl;

    return 0;
}
