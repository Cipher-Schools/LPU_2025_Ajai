
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
    cout << "Front: " << front->data << ", ";
    cout << "Rear: " << rear->data << endl;
    
}

void dequeue() {
    Node* temp;
    temp = front;
    
    front = front->next;
    delete temp;
    
}