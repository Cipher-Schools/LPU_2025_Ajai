struct Node {
    int data;
    Node* next;
};

Node* top = nullptr; 
void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    std::cout << value << " is pushed onto the stack" << std::endl;
}
void pop() {
    if (top == nullptr) {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    Node* poppedNode = top;
    top = top->next;

    std::cout << poppedNode->data << " is popped from the stack" << std::endl;
    delete poppedNode;
}

void displayStack() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    std::cout << "Elements in the stack: ";
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void initStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

