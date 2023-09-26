#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val) : data(val), left(NULL), right(NULL) {}
};

node *insert(node *root, int value)
{
    if (root == NULL)
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
    if (root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{   
    node *root = NULL;
    while (true)
    {
        cout<<"Insert Value (0 to stop):";
        int value;
        cin>>value;
        if(value==0)break;
        root=insert(root,value);
    }
    

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