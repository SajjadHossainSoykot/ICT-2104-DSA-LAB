#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

node* insert(node* root, int value)
{
    if(root==nullptr)return new node(value);

    if(value<root->data) root->left = insert(root->left,value);
    else root->right = insert(root->right,value);
    return root;
}

void inorder(node* root)
{
    if(root==nullptr)return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


int main()
{
    node *root=nullptr;
    cout<<"Enter values to insert in BST (0 to stop):"<<endl;
    while(1)
    {
        int value;
        cout<<"Enter Value: ";
        cin>>value;
        if(value==0)break;
        root = insert(root,value);
    }
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

}
