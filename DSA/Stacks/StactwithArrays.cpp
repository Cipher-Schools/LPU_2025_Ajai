#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of Stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push element onto stack
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    // Pop element from stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! No element to pop.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    // Peek (Top element)
    void peek() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Check if stack is full
    bool isFull() {
        return (top >= MAX - 1);
    }

    // Display stack elements
    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function to test Stack
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    if (s.isEmpty())
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";

    return 0;
}
