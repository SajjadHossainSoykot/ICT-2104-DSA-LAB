#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val):data(val),left(nullptr),right(nullptr) {}
};

node* insert(node *root, int value)
{
    if(root==nullptr)return new node(value);

    if(value<root->data)root->left=insert(root->left,value);
    else root->right=insert(root->right,value);

    return root;

}

bool search(node *root, int value)
{
    if(root==nullptr)return false;

    if(root->data==value)return true;
    else if(value<root->data)search(root->left,value);
    else search(root->right,value);

}

int main()
{
    node *root = nullptr;
    root = insert(root,5);
    insert(root,6);
    insert(root,7);
    insert(root,1);
    insert(root,2);
    insert(root,4);
    insert(root,3);

    cout<<"Enter Value to search: ";
    int value;
    cin>>value;

    cout<<(search(root,value)?"Value Found ":"Value not found ")<<"in BST"<<endl;
}
