

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int sumNodes(Node* root) {
    if (root == NULL)
        return 0;

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void deleteGreaterThanAverage(Node** root, int avg) {
    if (*root == NULL)
        return;

    deleteGreaterThanAverage(&((*root)->left), avg);
    deleteGreaterThanAverage(&((*root)->right), avg);

    if ((*root)->data > avg) {
        Node* temp = *root;
        *root = (*root)->left ? (*root)->left : (*root)->right;
        free(temp);
    }
}

