#include <iostream>
using namespace std;

void enqueue(int d) {
    Node* new_n = new Node;
    new_n->data = d;
    new_n->next = nullptr;
    if (front == nullptr && rear == nullptr) {
        front = rear = new_n;
    } else {
        rear->next = new_n;
        rear = new_n;
    }
}

void printFrontRear() {
    if (front != nullptr) {
        cout << "Front: " << front->data << ", ";
        cout << "Rear: " << rear->data << endl;
    }
}

void dequeue() {
    if (front == nullptr) return; // Check if queue is empty
    
    Node* temp = front;
    front = front->next;
    
    // If queue becomes empty after removal, update rear to nullptr
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
}
