#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isFull(Node *root)
{
    if (root == nullptr)
    {
        return true; // An empty tree is a full binary tree
    }

    // If both subtrees are null, it's a leaf node and considered full
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    // If both subtrees exist, recursively check if they are full binary trees
    if (root->left != nullptr && root->right != nullptr)
    {
        return isFull(root->left) && isFull(root->right);
    }

    // If either subtree is null, return false
    return false;
}



int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

bool isPerfect(Node *root)
{
    if (root == nullptr)
    {
        return true; // An empty tree is a perfect binary tree
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the left and right subtrees have the same height and are perfect binary trees
    return (leftHeight == rightHeight) && isPerfect(root->left) && isPerfect(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    bool Full = isFull(root);
    bool Perfect = isPerfect(root);

    cout << "Is it a full binary tree? " << (Full ? "Yes" : "No") << endl;
    cout << "Is it a perfect binary tree? " << (Perfect ? "Yes" : "No") << endl;

    return 0;
}
/* Output:

Is it a full binary tree? Yes
Is it a perfect binary tree? Yes

*/ 