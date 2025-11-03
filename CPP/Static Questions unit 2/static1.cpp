#include <iostream>
using namespace std;

void printHistogram(int *ptr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < *(ptr + i); j++) {
            cout << "x";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    // Check range of number of bars
    if (n < 1 || n > 20) {
        cout << "Invalid";
        return 0;
    }

    int heights[20];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Validate height range
    for (int i = 0; i < n; i++) {
        if (heights[i] < 1 || heights[i] > 10) {
            cout << "Invalid";
            return 0;
        }
    }

    // Call function
    printHistogram(heights, n);

    return 0;
}
