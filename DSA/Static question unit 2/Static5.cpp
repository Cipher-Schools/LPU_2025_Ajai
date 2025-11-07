#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* head = nullptr;

void createList() {
    Node* newNode, * temp;
    int data;
    cin >> data;

    while (data != -1) {
        newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cin >> data;
    }
    cout << "LINKED LIST CREATED" << endl;
}

void displayList() {
    Node* temp = head;
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
    cout << "The linked list after insertion at the beginning is:" << endl;
    displayList();
}

void insertAtEnd(int data) {
    Node* newNode = new Node(data);
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "The linked list after insertion at the end is:" << endl;
    displayList();
}

void insertBeforeValue(int value, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == value) {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    } else {
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found in the list" << endl;
        } else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
        }
    }
    cout << "The linked list after insertion before a value is:" << endl;
    displayList();
}

void insertAfterValue(int value, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found in the list" << endl;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    cout << "The linked list after insertion after a value is:" << endl;
    displayList();
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    cout << "The linked list after deletion from the beginning is:" << endl;
    displayList();
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    if (head->next == nullptr) { // Only one node
        delete head;
        head = nullptr;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    cout << "The linked list after deletion from the end is:" << endl;
    displayList();
}

void deleteBeforeValue(int value) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Operation not possible" << endl;
        return;
    }

    Node* temp = head->next; // start from second node
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->prev == nullptr) {
        cout << "Operation not possible" << endl;
    } else {
        Node* nodeToDelete = temp->prev;
        if (nodeToDelete->prev != nullptr) {
            nodeToDelete->prev->next = temp;
        } else {
            head = temp;
        }
        temp->prev = nodeToDelete->prev;
        delete nodeToDelete;
    }

    cout << "The linked list after deletion before a value is:" << endl;
    displayList();
}

void deleteAfterValue(int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Operation not possible" << endl;
    } else {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = temp;
        }
        delete nodeToDelete;
    }
    cout << "The linked list after deletion after a value is:" << endl;
    displayList();
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
    int option, data, value;

    while (1) {
        cin >> option;

        switch (option) {
            case 1:
                createList();
                break;
            case 2:
                displayList();
                break;
            case 3:
                cin >> data;
                insertAtBeginning(data);
                break;
            case 4:
                cin >> data;
                insertAtEnd(data);
                break;
            case 5:
                cin >> value >> data;
                insertBeforeValue(value, data);
                break;
            case 6:
                cin >> value >> data;
                insertAfterValue(value, data);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                cin >> value;
                deleteBeforeValue(value);
                break;
            case 10:
                cin >> value;
                deleteAfterValue(value);
                break;
            case 11:
                freeList();
                exit(0);
            default:
                cout << "Invalid option! Please try again" << endl;
        }
    }

    return 0;
}
