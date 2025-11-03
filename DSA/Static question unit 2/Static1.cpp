#include <iostream>
using namespace std;

struct MyNode {
    int val;
    MyNode* next;
};

// Insert at beginning
MyNode* insert_at_beginning(MyNode* head, int val) {
    MyNode* new_node = new MyNode;
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

// Insert at end
MyNode* insert_at_end(MyNode* head, int val) {
    MyNode* new_node = new MyNode;
    new_node->val = val;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    MyNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Insert at given position (1-indexed)
MyNode* insert_at_pos(MyNode* head, int pos, int val) {
    MyNode* new_node = new MyNode;
    new_node->val = val;
    new_node->next = NULL;

    // If position is 1, insert at beginning
    if (pos == 1) {
        new_node->next = head;
        return new_node;
    }

    MyNode* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // Invalid position (greater than length)
        delete new_node;
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Print linked list
void print_list(MyNode* head) {
    MyNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    MyNode* myList = NULL;

    while (true) {
        int choice, val, pos;
        if (!(cin >> choice)) break; // Handle EOF

        switch (choice) {
            case 1:
                cin >> val;
                myList = insert_at_beginning(myList, val);
                break;
            case 2:
                cin >> val;
                myList = insert_at_end(myList, val);
                break;
            case 3:
                cin >> pos >> val;
                myList = insert_at_pos(myList, pos, val);
                break;
            case 4:
                print_list(myList);
                break;
            case 5:
                cout << "Exiting";
                return 0;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    }

    return 0;
}


Single File Programming Question
Problem Statement



Rohit is developing a student record management system using a singly linked list. Each student record is represented by a number (roll number).



The system should allow the following operations:



Insert at the Beginning – A new student is added at the start of the list.
Insert at the End – A new student is added at the end of the list.
Insert at a Given Position – A new student is added at the specified position (1-indexed).
Print the Linked List – Displays the current student roll numbers in order.
Exit – Terminates the program.


If an invalid choice is entered, the system should display "Wrong choice".

Input format :
The input consists of a sequence of operations represented as integers.



If the choice is 1 or 2, the input consists of the choice followed by one integer (the value to be inserted).

If the choice is 3, the input consists of the choice followed by two integers: the position and the value to be inserted.

If the choice is 4, the input consists of only the choice, which prints the current linked list.

If the choice is 5, the input consists of only the choice, which terminates the program.

Output format :
For option 4, the output displays the elements present in the linked list, separated by a space.

For option 5, the output displays "Exiting" indicating the termination of the program.

If the choice is invalid, the output displays "Wrong choice"



Refer to the sample input and output for better understanding.

Code constraints :
1 ≤ value ≤ 1000

1 ≤ p ≤ N

1 ≤ N ≤ 1000

Sample test cases :
Input 1 :
1 10
1 20
2 30
3 2 25
1 37
2 50
4
5
Output 1 :
37 20 25 10 30 50 
Exiting
Input 2 :
2 10 
2 -20
1 40
3 4 50
4
1 100
7
5
Output 2 :
40 10 -20 50 
Wrong choice
Exiting
Input 3 :
1 10
4
2 20
7
5
Output 3 :
10 
Wrong choice
Exiting
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
