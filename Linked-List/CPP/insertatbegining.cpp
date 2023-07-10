#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
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
    cout<<"Before Insertion: ";
    displayList(head);
    // Insert values at the beginning
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    // Display the linked list
    cout<<"After Insertion: ";
    displayList(head);

    return 0;
}
/* Output:

Before Insertion: 1 2 3 4 5 
After Insertion: 10 20 30 1 2 3 4 5

*/