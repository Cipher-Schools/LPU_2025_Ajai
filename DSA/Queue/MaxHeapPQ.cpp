
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(30);

    cout << "Top element: " << pq.top() << endl; // 30

    pq.pop();

    cout << "Top after pop: " << pq.top() << endl; // 10

    return 0;
}
