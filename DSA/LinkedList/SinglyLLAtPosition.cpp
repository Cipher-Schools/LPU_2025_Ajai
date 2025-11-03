#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert at a specific position
void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = createNode(value);

    // Case 1: Insert at beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    int count = 1;

    // Traverse till (position - 1)
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }
    // If position is invalid
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    // Insert in between or at end
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete node at specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    // Case 1: Delete first node
    if (position == 1) {
        head = head->next;
        delete temp;
        return;
    }

    // Traverse till (position - 1)
    Node* prev = nullptr;
    int count = 1;
    while (temp != nullptr && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If position invalid
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Delete node
    prev->next = temp->next;
    delete temp;
}

// Main function
int main() {
    Node* head = nullptr;

    // Initial insertion
    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);
    insertAtPosition(head, 40, 4);
    cout << "Initial list: ";
    display(head);

    // Insert at specific position
    insertAtPosition(head, 25, 3);
    cout << "After inserting 25 at position 3: ";
    display(head);

    // Delete at specific position
    deleteAtPosition(head, 2);
    cout << "After deleting node at position 2: ";
    display(head);

    return 0;
}
