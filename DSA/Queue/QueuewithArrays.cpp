#include <iostream>
using namespace std;

#define SIZE 5   // size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == SIZE - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Insert element
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " inserted\n";
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } 
        else {
            front++;
        }
    }

    // Get front element
    int peek() {
        if (!isEmpty())
            return arr[front];
        cout << "Queue is EMPTY!\n";
        return -1;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
