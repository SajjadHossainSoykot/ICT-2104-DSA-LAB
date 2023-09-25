#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void insertFirst(struct node **head, int value)
{
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void insertMid(struct node **head, int value, int pos)
{
    if (pos<0)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (pos == 0)
    {
        insertFirst(head, value);
        return;
    }

    struct node *current = *head;
    struct node *prev = NULL;
    int count = 0;

    while (count<pos && current!=NULL)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if(current==NULL && count!=pos)
    {
        cout<<"Invalid Position. Can't Insert"<<endl;
        return;
    }
    struct node *newnode = new node;
    newnode->data= value;

    prev->next = newnode;
    newnode->next = current;
}


void insertLast(struct node **head, int value)
{
    struct node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
   if (*head == NULL)
    {
        // If the linked list is empty, set the head to the new node
        *head = newnode;
        return;
    }

    struct node *current = *head;
    while (current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newnode;

}

void display(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    struct node *head = new node;
    struct node *one = new node;
    struct node *two = new node;
    struct node *three = new node;

    one->data = 10;
    two->data = 20;
    three->data = 30;

    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;

    cout<<"Initial Linked List: ";
    display(head);

    while (true)
    {
        int choice, value, pos;
        cout << "\nInsert at\n1. First\n2. Middle\n3. End\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice!=4)
        {
            cout << "Enter value: ";
            cin>>value;
        }
        switch (choice)
        {
        case 1:
            insertFirst(&head, value);
            break;
        case 2:
            cout<<"Enter Position (0 based): ";
            cin>>pos;
            insertMid(&head, value, pos);
            break;
        case 3:
            insertLast(&head, value);
            break;
        case 4:
            cout << "Exiting\n";
            return 0;
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
        cout << "Updated Linked List : ";
        display(head);
    }
}