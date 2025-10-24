#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100];

    // Input number of elements
    cin >> n;

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
