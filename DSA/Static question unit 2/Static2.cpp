#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "The list is empty, cannot delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from the beginning." << endl;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "The list is empty, cannot delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Node deleted from the end." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
     
    delete temp->next;
    temp->next = nullptr;
    cout << "Node deleted from the end." << endl;
}

void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "The list is empty, cannot delete." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        
        cout << "Node deleted at position 1." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    cout << "Node deleted at position " << position << "." << endl;
}

void displayList() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice, data, position;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> data;
                insertAtEnd(data);
                break;
            case 2:
                deleteFromBeginning();
                break;
            case 3:
                deleteFromEnd();
                break;
            case 4:
                cin >> position;
                deleteAtPosition(position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                cout << "Exiting..." << endl;
                freeList();
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
