#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(node *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

bool isPerfect(node *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight == rightHeight) && isPerfect(root->left) && isPerfect(root->right);
}

bool isFull(node *root)
{
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        return isFull(root->left) && isFull(root->right);
    }
    return false;
}

node *insert(node *root, int value)
{
    if (root == nullptr)
        return new node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << (isFull(root) ? "Full" : "Not Full") << " BST" << endl;
    cout << (isPerfect(root) ? "Perfect" : "Not Perfect") << " BST" << endl;
}
