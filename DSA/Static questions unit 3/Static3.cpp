void initializeQueue() {
    front = -1;
    rear = -1;
}

bool isFull() {
    return rear == MAX_CUSTOMERS - 1;
}

bool isEmpty() {
    return front == -1;
}

int addCustomer(int customerID) {
    if (isFull()) {
        return 0;
    } else {
        rear++;
        customerIDs[rear] = customerID;
        if (front == -1) {
            front = 0;
        }
        return 1;
    }
}

int processCustomer() {
    if (isEmpty()) {
        return -1;
    } else {
        int customerID = customerIDs[front];
        front++;
        if (front > rear) {
            initializeQueue();
        }
        return customerID;
    }
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Checkout queue is empty." << endl;
    } else {
        cout << "Customers waiting in the checkout queue: ";
        for (int i = front; i <= rear; i++) {
            cout << customerIDs[i] << " ";
        }
        cout << endl;
    }
}