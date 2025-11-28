#include <iostream>
using namespace std;

#define MAX 50

struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

void initDeque(Deque *dq, int size) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = size;
}

bool isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == dq->size - 1) || dq->front == dq->rear + 1);
}

bool isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int key) {
    if (isFull(dq)) {
        cout << "Overflow" << endl;
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0)
        dq->front = dq->size - 1;
    else
        dq->front = dq->front - 1;
    dq->arr[dq->front] = key;
}

void insertRear(Deque *dq, int key) {
    if (isFull(dq)) {
        cout << "Overflow" << endl;
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == dq->size - 1)
        dq->rear = 0;
    else
        dq->rear = dq->rear + 1;

    dq->arr[dq->rear] = key;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        cout << "Queue Underflow" << endl;
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == dq->size - 1)
        dq->front = 0;
    else
        dq->front = dq->front + 1;
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        cout << "Queue Underflow" << endl;
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0)
        dq->rear = dq->size - 1;
    else
        dq->rear = dq->rear - 1;
}

int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(Deque *dq) {
    if (isEmpty(dq) || dq->rear < 0) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return dq->arr[dq->rear];
}

void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        cout << "Queue is empty" << endl;
        return;
    }

    int i;
    for (i = dq->front; i != dq->rear; i = (i + 1) % dq->size)
        cout << dq->arr[i] << " ";
    cout << dq->arr[i] << endl;
}
int main() {
    Deque dq;
    int size, front_input, rear_input;
    cin >> size;

    initDeque(&dq, size);

    int choice;
    for (int i = 0; i < size; i++) {
        cin >> choice;
        if (choice == 1) {
            cin >> front_input;
            insertFront(&dq, front_input);
        } else if (choice == 2) {
            cin >> rear_input;
            insertRear(&dq, rear_input);
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    cout << "Original Deque: ";
    printDeque(&dq);

    deleteFront(&dq);
    deleteRear(&dq);
    cout << "Deque after removing front and rear elements: ";
    printDeque(&dq);

    int new_front, new_rear;
    cin >> new_front;
    insertFront(&dq, new_front);

    cin >> new_rear;
    insertRear(&dq, new_rear);
    cout << "Deque after adding new front and rear elements: ";
    printDeque(&dq);
    
    return 0;
}
