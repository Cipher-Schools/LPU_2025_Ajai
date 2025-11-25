#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ------------------------------
// Student Structure
// ------------------------------
struct Student {
    string name;
    int marks;
};

// ------------------------------
// Custom Comparator
// Sorts students by marks in ASCENDING order
// (i.e., smallest marks has highest priority)
// ------------------------------
struct CompareMarks {
    bool operator()(const Student &a, const Student &b) {
        return a.marks > b.marks;  
        // if true → 'a' goes below 'b'
    }
};

int main() {

    // Priority Queue of Student type
    // Uses CompareMarks to order by marks
    priority_queue<Student, vector<Student>, CompareMarks> pq;

    // Insert Student objects into PQ
    pq.push({"Anish", 10});
    pq.push({"Gulsan", 30});
    pq.push({"Ayush", 20});

    // ------------------------------
    // Printing the priority queue
    // ------------------------------
    cout << "Students sorted by marks (low → high):\n\n";

    while (!pq.empty()) {
        Student topStudent = pq.top();
        cout << topStudent.name << " -> " << topStudent.marks << endl;
        pq.pop();
    }

    return 0;
}
