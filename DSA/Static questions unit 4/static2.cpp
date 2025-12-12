#include <iostream>
#include <queue>
using namespace std;

// Structure for BST node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Function to delete a node from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Function to perform level order traversal of BST
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    
    int n, x, y;
    cin >> n;
    TreeNode* root = NULL;
    
    // Constructing the initial BST
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "Initial BST: ";
    levelOrderTraversal(root);
    cout << endl;
    
    // Inserting a new node
    cin >> x;
    root = insert(root, x);
    cout << "BST after inserting a new node " << x << ": ";
    levelOrderTraversal(root);
    cout << endl;
    
    // Deleting a node
    cin >> y;
    root = deleteNode(root, y);
    cout << "BST after deleting node " << y << ": ";
    levelOrderTraversal(root);
    cout << endl;
    
    return 0;
}
