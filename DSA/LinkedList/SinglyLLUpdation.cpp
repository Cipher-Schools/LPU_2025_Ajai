#include <iostream>
using namespace std;

// Define node structure
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

// Function to insert node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to update a node’s value by position
void updateNode(Node* head, int position, int newValue) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!\n";
    } else {
        cout << "Value at position " << position << " updated from "
             << temp->data << " to " << newValue << ".\n";
        temp->data = newValue;
    }
}

// Main function
int main() {
    Node* head = nullptr;

    // Create linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original Linked List: ";
    displayList(head);

    int pos, val;
    cout << "Enter position to update: ";
    cin >> pos;
    cout << "Enter new value: ";
    cin >> val;

    updateNode(head, pos, val);

    cout << "Updated Linked List: ";
    displayList(head);

    return 0;
}
