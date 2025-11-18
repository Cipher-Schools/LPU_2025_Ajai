#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // -------------------------------
    // 1. Input using fixed size
    // -------------------------------
    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> v1(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    cout << "Vector v1: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";


    // -------------------------------
    // 2. Input using push_back()
    // -------------------------------
    int m;
    cout << "\nEnter size for second vector: ";
    cin >> m;

    vector<int> v2;
    cout << "Enter " << m << " elements:\n";
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    cout << "Vector v2: ";
    for (int x : v2) cout << x << " ";
    cout << "\n";


    // -------------------------------
    // 3. Range-based loop input
    // -------------------------------
    int k;
    cout << "\nEnter size for third vector: ";
    cin >> k;

    vector<int> v3(k);
    cout << "Enter " << k << " elements:\n";
    for (int &x : v3) {
        cin >> x;
    }

    cout << "Vector v3: ";
    for (int x : v3) cout << x << " ";
    cout << "\n";


    // -------------------------------
    // 4. Basic operations
    // -------------------------------
    vector<int> demo;

    demo.push_back(10);
    demo.push_back(5);
    demo.push_back(20);

    cout << "\nDemo Vector: ";
    for (int x : demo) cout << x << " ";

    cout << "\nSize: " << demo.size();
    cout << "\nFront: " << demo.front();
    cout << "\nBack: " << demo.back();

    // sort
    sort(demo.begin(), demo.end());

    cout << "\nSorted Demo Vector: ";
    for (int x : demo) cout << x << " ";
    cout << "\n";


    // -------------------------------
    // 5. insert() and erase()
    // -------------------------------
    demo.insert(demo.begin() + 1, 99); // insert 99 at index 1

    cout << "\nAfter insert 99 at index 1: ";
    for (int x : demo) cout << x << " ";

    demo.erase(demo.begin() + 2); // erase index 2

    cout << "\nAfter erasing element at index 2: ";
    for (int x : demo) cout << x << " ";
    cout << "\n";


    // -------------------------------
    // END
    // -------------------------------
    cout << "\n--- Program Finished ---\n";

    return 0;
}
