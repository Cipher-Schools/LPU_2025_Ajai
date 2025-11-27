#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<string, int> mp;

    // Insert values
    mp["Ajay"] = 90;
    mp["Rahul"] = 85;
    mp["Kiran"] = 95;

    // Access a value
    cout << "Marks of Ajay: " << mp["Ajay"] << endl;

    // Update a value
    mp["Rahul"] = 99;

    // Check if key exists
    if (mp.find("Kiran") != mp.end()) {
        cout << "Kiran exists in map\n";
    }

    // Erase a key
    mp.erase("Ajay");

    // Print single known key
    cout << "Rahul Marks: " << mp["Rahul"] << endl;

    return 0;
}