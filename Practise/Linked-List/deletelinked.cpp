#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void checkEmpty(struct node **head)
{
    if (*head == NULL)
    {
        cout << "Linked list is empty. Cannot delete.\n";
        return;
    }
}

void deleteFirst(struct node **head)
{
    checkEmpty(head);
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteMid(struct node **head, int pos)
{
    checkEmpty(head);
    if (pos < 0)
    {
        printf("Invalid position. Cannot delete.\n");
        return;
    }
    if (pos == 0)
    {
        deleteFirst(head);
        return;
    }

    struct node *current = *head;
    struct node *prev = NULL;
    int count = 0;

    while (count < pos && current != NULL)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        cout << "Invalid Position. Can't Delete" << endl;
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteLast(struct node **head)
{
    checkEmpty(head);

    struct node *current = *head;
    struct node *prev = NULL;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        free(*head); // Only one node in the list
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
        free(current);
    }
}

void display(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    struct node *head = new node;
    struct node *one = new node;
    struct node *two = new node;
    struct node *three = new node;
    struct node *four = new node;
    struct node *five = new node;

    one->data = 10;
    two->data = 20;
    three->data = 30;
    four->data = 40;
    five->data = 50;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;
    head = one;

    cout << "Initial Linked List: ";
    display(head);

    while (true)
    {
        int choice, pos;
        cout << "\nDelete at\n1. First\n2. Middle\n3. End\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            deleteFirst(&head);
            break;
        case 2:
            cout << "Enter Position (0 based): ";
            cin >> pos;
            deleteMid(&head, pos);
            break;
        case 3:
            deleteLast(&head);
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