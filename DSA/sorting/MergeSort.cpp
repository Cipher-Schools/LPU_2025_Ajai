#include <bits/stdc++.h>
using namespace std;

// ----------------------------
// Merge two sorted halves
// ----------------------------
void mergeArray(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp;  // temporary array
    int i = l;         // pointer for left half
    int j = mid + 1;   // pointer for right half

    // Merge elements in sorted order
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // If elements left in left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // If elements left in right half
    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy temp array back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[l + k] = temp[k];
    }
}

// ----------------------------
// Merge Sort Function
// ----------------------------
void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;  // base case

    int mid = l + (r - l) / 2;

    // Recursively sort both halves
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // Merge sorted halves
    mergeArray(arr, l, mid, r);
}

// ----------------------------
// Main Function
// ----------------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
