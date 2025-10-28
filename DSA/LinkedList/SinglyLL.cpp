#include <iostream>
using namespace std;
// Node structure define
struct Node{
    int data;
    Node* next;
};

// create a new node 
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data=value;
    newNode->next=nullptr;
    return newNode;
}

void displayList(Node* head){
    Node* temp=head;
    cout<<"Linked List:";
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

int main() {
    Node* head =nullptr;
    Node* tail=nullptr;
    int n, value;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<<"enter value for a node "<<i+1<<":";
        cin>>value;
        Node* pranav = createNode(value);
        
        if(head==nullptr){
            head=pranav;
            tail=pranav;
        }else{
            tail->next=pranav;
            tail=pranav;
        }
    }
   
   displayList(head);
   

    return 0;
}

// Output:

// enter the number of nodes: 5
// enter value for a node 1:4
// enter value for a node 2:3
// enter value for a node 3:2
// enter value for a node 4:6
// enter value for a node 5:7
// Linked List:4->3->2->6->7->null
