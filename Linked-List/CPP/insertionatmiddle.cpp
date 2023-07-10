#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void insertAtMiddle(Node *&head, int value, int position)
{
    Node *newNode = new Node;
    newNode->data = value;

    // If the list is empty or position is 0, insert at the beginning
    if (head == nullptr || position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    int currentPosition = 0;

    // Traverse to the position before the desired position
    while (current->next != nullptr && currentPosition < position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    // Insert the new node at the desired position
    newNode->next = current->next;
    current->next = newNode;
}

void displayList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
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
    cout << "Before Insertion: ";
    displayList(head);
   // Insert values at the middle
    insertAtMiddle(head, 10, 0);  // Insert 1 at position 0 (beginning)
    insertAtMiddle(head, 30, 1);  // Insert 3 at position 1 (middle)
    insertAtMiddle(head, 20, 1);  // Insert 2 at position 1 (middle)

    // Display the linked list
    cout << "After Insertion at Middle: ";
    displayList(head);

    return 0;
}
/* Output:

Before Insertion: 1 2 3 4 5 
After Insertion at Middle: 10 20 30 1 2 3 4 5

*/