#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Task {
    int priority;
    int deadline;
    string name;
};

bool compare(const Task& a, const Task& b) {
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    }
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cin >> n;
    
    Task* tasks = new Task[n];
    
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].priority >> tasks[i].deadline >> tasks[i].name;
    }
    
    sort(tasks, tasks + n, compare);
    
    cout << "Executed Tasks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << tasks[i].name << endl;
    }
    
    delete[] tasks;
    return 0;
}