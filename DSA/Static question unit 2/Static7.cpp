#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createCircularList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; // Make it circular
    return head;
}

Node* removeLast(Node* head) {
    if (head == nullptr || head->next == head)
        return nullptr;

    Node* temp = head;
    Node* prev = nullptr;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; // Last node removed
    delete temp;
    return head;
}

void display(Node* head) {
    if (head == nullptr)
        return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int N;
    cin >> N;

    int arr[30];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Node* head = createCircularList(arr, N);
    head = removeLast(head);
    display(head);

    return 0;
}

