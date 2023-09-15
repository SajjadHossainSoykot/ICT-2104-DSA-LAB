#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to search for a value in a Binary Search Tree (BST)
bool search(Node* root, int target) {
    if (root == nullptr) {
        return false; // Value not found
    }

    if (root->data == target) {
        return true; // Value found
    } else if (target < root->data) {
        return search(root->left, target); // Search in the left subtree
    } else {
        return search(root->right, target); // Search in the right subtree
    }
}

int main() {
    Node* root = nullptr;

    // Insert values into the BST
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int target;

    cout << "Enter the value to search for: ";
    cin >> target;

    bool found = search(root, target);

    if (found) {
        cout << "Value " << target << " found in the BST." << endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }

    return 0;
}
/* Output:

Enter the value to search for: 4
Value 4 found in the BST.

*/