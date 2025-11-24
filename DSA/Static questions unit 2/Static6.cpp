#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtPosition(int data, int position) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // If list is empty
    if (head == nullptr) {
        cout << "The list is empty";
        return;
    }

    // Count current nodes
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Invalid position check
    if (position < 1 || position > count + 1) {
        cout << "Invalid position" << endl;
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return;
    }

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    temp = head;
    int i = 1;
    while (i < position - 1 && temp->next != nullptr) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int value;
    Node* tail = nullptr;

    // Read initial list
    while (cin >> value && value != -1) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int data, position;
    cin >> data >> position;

    // Check for empty list before insertion
    if (head == nullptr) {
        cout << "The list is empty";
        return 0;
    }

    insertAtPosition(data, position);
    display();

    return 0;
}
