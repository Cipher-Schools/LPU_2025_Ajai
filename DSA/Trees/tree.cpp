#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int value){
        data=value;
        left=right=NULL;
    }
};

// pre   -:  root left right
void preorderIterative(Node* root){
    if(root==NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        
        if(curr->right){
            st.push(curr->right);
        }
        
        if(curr->left){
            st.push(curr->left);
        }
    }    
}


// left right root;
void postorderIterative(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* Lastvisited=NULL;
    Node* curr = root;
    while(!st.empty() || curr!=nullptr){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }else{
            Node* peekNode = st.top();
            if(peekNode->right!=nullptr && Lastvisited!=peekNode->right){
                curr=peekNode->right;
            }else{
                cout<<peekNode->data<<" ";
                Lastvisited=peekNode;
                st.pop();
            }
        }
    }
    
}

int main()
{
    Node* root = new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    
    
    
    cout<<"preorder: ";
    preorderIterative(root);
    cout<<endl;
    
    cout<<"postorder: ";
    postorderIterative(root);
    
    


    return 0;
}