// Linked list traversal in C++
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void traverseLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    /*new Node{1, nullptr} dynamically allocates memory for a new 
    Node object and initializes it with a value of 1 and a nullptr for the next pointer.
    The resulting memory address of the newly created Node object is assigned to the head pointer.*/
    
    Node *head = new Node{1, nullptr};
    Node *second = new Node{2, nullptr};
    Node *third = new Node{3, nullptr};
    Node *fourth = new Node{4, nullptr};
    Node *fifth = new Node{5, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Traverse the linked list and print the values
    cout<<"Traversing Linked List: ";
    traverseLinkedList(head);

    // Clean up memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
/* Output:

Traversing Linked List: 1 2 3 4 5

*/