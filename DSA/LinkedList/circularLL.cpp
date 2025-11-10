#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* last; // keeps track of the last node for easy insertion at end

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert at the end
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (last == nullptr) {  // if list is empty
            last = newNode;
            last->next = last;  // circular link
        } else {
            newNode->next = last->next; // first node
            last->next = newNode;
            last = newNode;
        }
    }

    // Insert at the beginning
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    // Insert after a given node value
    void insertAfter(int key, int val) {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = last->next;
        do {
            if (curr->data == key) {
                Node* newNode = new Node(val);
                newNode->next = curr->next;
                curr->next = newNode;

                if (curr == last)
                    last = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node with value " << key << " not found!\n";
    }

    // Delete a node by value
    void deleteNode(int key) {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;

        do {
            if (curr->data == key) {
                if (curr == last && curr == last->next) { // only one node
                    delete curr;
                    last = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == last)
                        last = prev;
                    delete curr;
                }
                cout << "Deleted " << key << " from list.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node with value " << key << " not found!\n";
    }

    // Display all nodes
    void display() {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }

    // Search for an element
    void search(int key) {
        if (last == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "Element " << key << " not found!\n";
    }
};

// Main function
int main() {
    CircularLinkedList cll;
    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertEnd(30);
    cll.insertBegin(5);
    cll.display();

    cll.insertAfter(20, 25);
    cll.display();

    cll.deleteNode(10);
    cll.display();

    cll.search(25);
    cll.search(100);

    return 0;
}
