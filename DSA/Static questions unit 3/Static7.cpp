#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Deque {
    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    Deque(int cap) {
        capacity = cap;
        size = 0;
        front = rear = nullptr;
    }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
    void insertFront(int value) {
        if (isFull()) { cout << "Overflow\n"; return; }
        Node* newNode = new Node{value, front, nullptr};
        if (isEmpty()) rear = newNode;
        else front->prev = newNode;
        front = newNode;
        size++;
        cout << value << "\n";
    }
    void insertRear(int value) {
        if (isFull()) { cout << "Overflow\n"; return; }
        Node* newNode = new Node{value, nullptr, rear};
        if (isEmpty()) front = newNode;
        else rear->next = newNode;
        rear = newNode;
        size++;
        cout << value << "\n";
    }
    void deleteFront() {
        if (isEmpty()) { cout << "Underflow\n"; return; }
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
        size--;
    }
    void deleteRear() {
        if (isEmpty()) { cout << "Underflow\n"; return; }
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
        size--;
    }
    void getFront() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << front->data << "\n";
    }
    void getRear() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << rear->data << "\n";
    }
    void printDeque() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    int capacity, choice, value;
    cin >> capacity;
    Deque dq(capacity);
    while (true) {
        cin >> choice;
        switch (choice) {
            case 1: cin >> value; dq.insertFront(value); break;
            case 2: cin >> value; dq.insertRear(value); break;
            case 3: dq.deleteFront(); break;
            case 4: dq.deleteRear(); break;
            case 5: dq.getFront(); break;
            case 6: dq.getRear(); break;
            case 7: dq.printDeque(); break;
            case 8: cout << "Exiting\n"; return 0;
            default: cout << "Invalid choice\n";
        }
    }
}


