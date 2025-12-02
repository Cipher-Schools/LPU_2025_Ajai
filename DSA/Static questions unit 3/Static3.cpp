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
        if (front == -1) {
            front = 0;
        }
        rear++;
        customerIDs[rear] = customerID;
        return 1;
    }
}

// Updated to match the Footer's expected format (takes a pointer)
int processCustomer(int *id) {
    if (isEmpty()) {
        return 0; // Return 0 to indicate failure/empty
    } else {
        *id = customerIDs[front]; // Store the ID in the pointer
        front++;
        if (front > rear) {
            initializeQueue();
        }
        return 1; // Return 1 to indicate success
    }
}

// Updated to use printf instead of cout
void displayQueue() {
    if (isEmpty()) {
        printf("Checkout queue is empty.\n");
    } else {
        printf("Customers waiting in the checkout queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", customerIDs[i]);
        }
        printf("\n");
    }
}
