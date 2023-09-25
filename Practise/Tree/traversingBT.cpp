#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

node *insert(node *root, int value)
{
    if (root == nullptr)
    {
        return new node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
        root->right = insert(root->right, value);
}

void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{   
    node *root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
}