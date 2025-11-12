#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
};

// Stack class
class Stack {
    Node* top; // Pointer to top node

public:
    Stack() { top = NULL; } // Constructor initializes stack as empty

    // Push operation
    void push(int value) {
        Node* newNode = new Node(); // create new node
        newNode->data = value;
        newNode->next = top; // new node points to previous top
        top = newNode; // update top
        cout << value << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow (Empty Stack)\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next; // move top to next
        delete temp; // free memory
    }

    // Peek (view top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Display elements
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free all nodes
    ~Stack() {
        while (!isEmpty())
            pop();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}
