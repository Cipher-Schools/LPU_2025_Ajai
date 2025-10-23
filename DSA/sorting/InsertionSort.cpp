#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int pos = i - 1;

        while (pos >= 0 && arr[pos] > current) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = current;
    }
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Array after sorting:\n";
    display(arr, n);
    return 0;
}
