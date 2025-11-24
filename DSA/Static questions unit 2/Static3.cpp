#include <iostream>
using namespace std;

struct Node {
    int membershipNumber;
    Node* next;
};

// Function to create a new node
Node* createNode(int membershipNumber) {
    Node* newNode = new Node();
    newNode->membershipNumber = membershipNumber;
    newNode->next = nullptr;
    return newNode;
}

// Function to check if membership exists in the list
bool isMemberInList(Node* head, int membershipToCheck) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->membershipNumber == membershipToCheck)
            return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Build the linked list
    for (int i = 0; i < N; i++) {
        int membershipNumber;
        cin >> membershipNumber;
        Node* newNode = createNode(membershipNumber);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int membershipToCheck;
    cin >> membershipToCheck;

    // Check membership existence
    if (isMemberInList(head, membershipToCheck)) {
        cout << "Membership number " << membershipToCheck << " is active";
    } else {
        cout << "Membership number " << membershipToCheck << " is not in the list";
    }

    return 0;
}
