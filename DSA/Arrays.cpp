//  Arrays and Core Operations (Traversal, Insertion, Deletion, Updation)

#include <iostream>
using namespace std;

// --------------------------------------
// 1️⃣ Basic Array Declaration & Access
// --------------------------------------
void basicArray() {
    cout << "\n--- Basic Array Example ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "First element: " << arr[0] << endl;  // 10
    // Dry Run: arr = [10,20,30,40,50]
    // arr[0] → 10
}

// --------------------------------------
// 2️⃣ Traversal (Forward & Reverse)
// --------------------------------------
void traversal() {
    cout << "\n--- Array Traversal ---\n";
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Forward Traversal: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";

    cout << "\nReverse Traversal: ";
    for (int i = 4; i >= 0; i--) cout << arr[i] << " ";

    cout << endl;
    // Dry Run:
    // i=0→1, i=1→2, i=2→3, i=3→4, i=4→5
}

// --------------------------------------
// 3️⃣ Insertion Operations
// --------------------------------------
void insertAtBeginning() {
    cout << "\n--- Insert at Beginning ---\n";
    int arr[10] = {10, 20, 30, 40};
    int n = 4, val = 5;
    for (int i = n; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = val;
    n++;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40] -> [5,10,20,30,40]
}

void insertInMiddle() {
    cout << "\n--- Insert in Middle ---\n";
    int arr[10] = {10, 20, 30, 40};
    int n = 4, pos = 2, val = 99;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40] -> [10,20,99,30,40]
}

void insertAtEnd() {
    cout << "\n--- Insert at End ---\n";
    int arr[10] = {10, 20, 30, 40};
    int n = 4;
    arr[n] = 50;
    n++;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40] -> [10,20,30,40,50]
}

// --------------------------------------
// 4️⃣ Deletion Operations
// --------------------------------------
void deleteFromBeginning() {
    cout << "\n--- Delete from Beginning ---\n";
    int arr[10] = {10, 20, 30, 40};
    int n = 4;
    for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40] -> [20,30,40]
}

void deleteFromMiddle() {
    cout << "\n--- Delete from Middle ---\n";
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5, pos = 2;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40,50] -> [10,20,40,50]
}

void deleteFromEnd() {
    cout << "\n--- Delete from End ---\n";
    int arr[10] = {10, 20, 30, 40};
    int n = 4;
    n--;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40] -> [10,20,30]
}

// --------------------------------------
// 5️⃣ Updation Operations
// --------------------------------------
void updateAtBeginning() {
    cout << "\n--- Update at Beginning ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    arr[0] = 99;
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40,50] -> [99,20,30,40,50]
}

void updateInMiddle() {
    cout << "\n--- Update in Middle ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    arr[2] = 55;
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40,50] -> [10,20,55,40,50]
}

void updateAtEnd() {
    cout << "\n--- Update at End ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    arr[4] = 77;
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    // Dry Run: [10,20,30,40,50] -> [10,20,30,40,77]
}

// --------------------------------------
// 6️⃣ Main Function: Demo Runner
// --------------------------------------
int main() {
    cout << "\n==============================\n";
    cout << "📘 ARRAYS IN C++ - DEMO PROGRAM\n";
    cout << "==============================\n";

    basicArray();
    traversal();

    insertAtBeginning();
    insertInMiddle();
    insertAtEnd();

    deleteFromBeginning();
    deleteFromMiddle();
    deleteFromEnd();

    updateAtBeginning();
    updateInMiddle();
    updateAtEnd();

    cout << "\n✅ End of Arrays Demo.\n";
    cout << "Try Homework: Insert & Delete at different positions.\n";
    return 0;
}
