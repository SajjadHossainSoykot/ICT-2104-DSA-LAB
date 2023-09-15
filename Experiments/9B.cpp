#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into a Binary Search Tree (BST)
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert values into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    // Display the resulting BST using inorder traversal
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
/* Output:

Inorder Traversal of the BST: 1 3 4 5 7 8 9

*/