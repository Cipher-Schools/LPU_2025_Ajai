#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(30);

    cout << "Top element: " << minHeap.top() << endl; // 5

    minHeap.pop();

    cout << "Top after pop: " << minHeap.top() << endl; // 10

    return 0;
}
