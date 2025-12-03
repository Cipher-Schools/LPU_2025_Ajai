#include <iostream>
using namespace std;

// (pivot = last element)
int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];        // pivot
    int i = low - 1;              // pointer for greater element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {    // smaller element found
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  // place pivot in correct position
    return i + 1;                 // return pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high);  // pivot index

        quickSort(arr, low, pi - 1);  // left
        quickSort(arr, pi + 1, high); // right
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
}
