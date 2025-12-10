#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* insertNode(Node* root,int value){
    if(root==NULL){
        Node* newNode = new Node();
        newNode->data= value;
        newNode->left=NULL;
        newNode->right=NULL;
        
        return newNode;
    }
    
    
    if(value<root->data){
        root->left= insertNode(root->left,value);
    }else{
        root->right=insertNode(root->right,value);
    }
    
    return root;
}





// void inordertraversal(Node* root){
       
// }


Node* findmin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}


Node* deleteNode(Node* root,int key){
    if(root==NULL) return root;
    
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }else{
        // no child
        if(root->left==NULL&& root->right==NULL) return NULL;
        
        // one child 
        else if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        // two child
        Node* temp = findmin(root->right);
        root->data=temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}


Node* updation(Node* root, int oldvalue, int newValue){
    root=deleteNode(root,oldvalue);
    root=insertNode(root,newValue);
    return root;
}




int main()
{
   Node* root = NULL;
   
   root= insertNode(root,10);
   root= insertNode(root,20);
   root=insertNode(root,5);
   root=insertNode(root,3);
   
   cout<<"Binary Search Tree created";
   cout<<endl;
//   inordertraversal(root);
   root= updation(root,10,22);
   
   

    return 0;
}

 
 60 -> root


         60
       30   70 
    20  40    80