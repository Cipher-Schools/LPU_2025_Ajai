#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertAtPosition(int data, int pos) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Invalid position
        if (pos < 1 || pos > count + 1) {
            cout << "Invalid position" << endl;
            displayList();
            return;
        }

        Node* newNode = createNode(data);

        // Case 1: Insert at beginning
        if (pos == 1) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = newNode;
        }
        // Case 2: Insert at end
        else if (pos == count + 1) {
            insertAtEnd(data);
            return displayList();
        }
        // Case 3: Insert in middle
        else {
            Node* current = head;
            for (int i = 1; i < pos - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        displayList();
    }
};

int main() {
    DoublyLinkedList dList;
    int n;
    cin >> n;

    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        dList.insertAtEnd(data);
    }

    int newData, pos;
    cin >> newData >> pos;

    dList.insertAtPosition(newData, pos);

    return 0;
}
