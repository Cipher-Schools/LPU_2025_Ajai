#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at given position (1-based index)
void insertAtPosition(int data, int pos) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = createNode(data);

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

// Delete from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    if (temp->prev != nullptr)
        temp->prev->next = nullptr;
    else
        head = nullptr;

    delete temp;
}

// Delete from given position
void deleteFromPosition(int pos) {
    if (head == nullptr || pos <= 0) {
        cout << "Invalid position or empty list!" << endl;
        return;
    }

    Node* temp = head;

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    int count = 1;
    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

// Delete by value
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    // If the node to delete is head
    if (temp->data == value) {
        deleteFromBeginning();
        return;
    }

    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value not found!" << endl;
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

// Display forward
void displayForward() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "List (Forward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display backward
void displayBackward() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "List (Backward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Count nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search for an element
void searchElement(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found!" << endl;
}

// MAIN FUNCTION
int main() {
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Delete by Value\n";
        cout << "8. Display Forward\n";
        cout << "9. Display Backward\n";
        cout << "10. Count Nodes\n";
        cout << "11. Search Element\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteFromPosition(pos);
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(value);
                break;
            case 8:
                displayForward();
                break;
            case 9:
                displayBackward();
                break;
            case 10:
                cout << "Total nodes: " << countNodes() << endl;
                break;
            case 11:
                cout << "Enter value to search: ";
                cin >> value;
                searchElement(value);
                break;
            case 12:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 12);

    return 0;
}
