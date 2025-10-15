//  Demonstrates Linear Search, finding Max, Min, 2nd & 3rd largest elements

#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

// 1️⃣ Linear Search
void linearSearch() {
    cout << "\n--- Linear Search ---\n";
    int arr[6] = {10, 25, 30, 5, 40, 15};
    int n = 6, key = 40, found = -1;

    // Linear search loop
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    // Display results
    if (found != -1)
        cout << "Element " << key << " found at index " << found << endl;
    else
        cout << "Element not found." << endl;

    // Dry Run Example:
    // arr = [10,25,30,5,40,15], key = 40
    // i=0 (10!=40)
    // i=1 (25!=40)
    // i=2 (30!=40)
    // i=3 (5!=40)
    // i=4 (40==40 ✅ found at index 4)
}

// 2️⃣ Find Maximum Element
void findMax() {
    cout << "\n--- Find Maximum Element ---\n";
    int arr[6] = {10, 25, 30, 5, 40, 15};
    int n = 6, maxVal = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Maximum element is: " << maxVal << endl;

    // Dry Run:
    // Start: maxVal = -∞
    // i=0 → 10 > -∞ → maxVal = 10
    // i=1 → 25 > 10 → maxVal = 25
    // i=2 → 30 > 25 → maxVal = 30
    // i=3 → 5 < 30 → no change
    // i=4 → 40 > 30 → maxVal = 40 ✅
    // i=5 → 15 < 40 → no change
}

// 3️⃣ Find Minimum Element
void findMin() {
    cout << "\n--- Find Minimum Element ---\n";
    int arr[6] = {10, 25, 30, 5, 40, 15};
    int n = 6, minVal = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    cout << "Minimum element is: " << minVal << endl;

    // Dry Run:
    // Start: minVal = +∞
    // i=0 → 10 < ∞ → minVal = 10
    // i=1 → 25 > 10 → no change
    // i=2 → 30 > 10 → no change
    // i=3 → 5 < 10 → minVal = 5 ✅
    // i=4 → 40 > 5 → no change
    // i=5 → 15 > 5 → no change
}

// 4️⃣ Find 2nd Largest Element
void findSecondLargest() {
    cout << "\n--- Find 2nd Largest Element ---\n";
    int arr[6] = {10, 25, 30, 5, 40, 15};
    int n = 6;

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    cout << "Second largest element is: " << second << endl;

    // Dry Run:
    // arr = [10,25,30,5,40,15]
    // first = -∞, second = -∞
    // 10 > -∞ → first=10, second=-∞
    // 25 > 10 → first=25, second=10
    // 30 > 25 → first=30, second=25
    // 5 < 30 → no change
    // 40 > 30 → first=40, second=30 ✅
    // 15 < 30 → no change
}

// 5️⃣ Find 3rd Largest Element
void findThirdLargest() {
    cout << "\n--- Find 3rd Largest Element ---\n";
    int arr[6] = {10, 25, 30, 5, 40, 15};
    int n = 6;

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    cout << "Third largest element is: " << third << endl;

    // Dry Run:
    // arr = [10,25,30,5,40,15]
    // Step by step:
    // first=40, second=30, third=25 ✅
}

// --------------------------------------------------------------
// 🧩 Main Function
// --------------------------------------------------------------
int main() {
    cout << "\n==============================\n";
    cout << "📘 LINEAR SEARCH & MAX/MIN DEMO\n";
    cout << "==============================\n";

    linearSearch();
    findMax();
    findMin();
    findSecondLargest();
    findThirdLargest();

    cout << "\n✅ End of Linear Search Demo.\n";
    cout << "Homework: Try finding 2nd smallest element.\n";
    return 0;
}
