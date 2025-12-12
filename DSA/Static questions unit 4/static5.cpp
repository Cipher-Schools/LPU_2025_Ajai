#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float grades;
    struct Student* left;
    struct Student* right;
};

// Function to create a new student node
struct Student* createStudent(int rollNumber, const char* name, float grades) {
    struct Student* newStudent = new struct Student;
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    newStudent->grades = grades;
    newStudent->left = newStudent->right = nullptr;
    return newStudent;
}

// Function to insert a new student into the BST
struct Student* insertStudent(struct Student* root, int rollNumber, const char* name, float grades) {
    if (root == nullptr) {
        return createStudent(rollNumber, name, grades);
    }

    if (rollNumber < root->rollNumber) {
        root->left = insertStudent(root->left, rollNumber, name, grades);
    } else if (rollNumber > root->rollNumber) {
        root->right = insertStudent(root->right, rollNumber, name, grades);
    }

    return root;
}

// Function to perform an inorder traversal of the BST
void inorderTraversal(struct Student* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << "Roll Number: " << root->rollNumber << ", Name: " << root->name << ", Grades: " << fixed << setprecision(2) << root->grades << endl;
        inorderTraversal(root->right);
    }
}

// Function to search for a student by roll number
struct Student* searchStudent(struct Student* root, int rollNumber) {
    if (root == nullptr || root->rollNumber == rollNumber) {
        return root;
    }

    if (rollNumber < root->rollNumber) {
        return searchStudent(root->left, rollNumber);
    } else {
        return searchStudent(root->right, rollNumber);
    }
}

// Function to find the minimum value node in a BST
struct Student* findMin(struct Student* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a student by roll number
struct Student* deleteStudent(struct Student* root, int rollNumber) {
    if (root == nullptr) {
        cout << "Student not found." << endl;
        return root;  // Student not found, return root unchanged
    }

    if (rollNumber < root->rollNumber) {
        root->left = deleteStudent(root->left, rollNumber);
    } else if (rollNumber > root->rollNumber) {
        root->right = deleteStudent(root->right, rollNumber);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            struct Student* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            struct Student* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Student* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->rollNumber = temp->rollNumber;
        strcpy(root->name, temp->name);
        root->grades = temp->grades;

        // Delete the inorder successor
        root->right = deleteStudent(root->right, temp->rollNumber);
    }

    return root;
}

// Function to free the memory allocated for the BST
void freeBST(struct Student* root) {
    if (root != nullptr) {
        freeBST(root->left);
        freeBST(root->right);
        delete root;
    }
}

int main() {
    struct Student* root = nullptr;
    int choice, rollNumber;
    char name[50];
    float grades;
    struct Student* result;

    do {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> rollNumber;
                cin >> name;
                cin >> grades;
                root = insertStudent(root, rollNumber, name, grades);
                break;
            case 2:
                cin >> rollNumber;
                root = deleteStudent(root, rollNumber);
                break;
            case 3:
                cin >> rollNumber;
                result = searchStudent(root, rollNumber);
                if (result != nullptr) {
                    cout << "Student found - Roll Number: " << result->rollNumber << ", Name: " << result->name << ", Grades: " << fixed << setprecision(2) << result->grades << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            case 4:
                cout << "Student Database (inorder):" << endl;
                inorderTraversal(root);
                break;
            case 5:
                freeBST(root);
                cout << "Exiting program." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}