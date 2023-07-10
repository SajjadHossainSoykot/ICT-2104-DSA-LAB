// Linked list insertion at begining in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node
{
    float value;
    struct node *next;
};

// Print the linked list
void printList(struct node *p)
{
    while (p != NULL)
    {
        printf(" %f ", p->value);
        p = p->next;
    }
}

// Driver program
int main()
{
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocation
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Asign
    one->value = 500;
    two->value = 200;
    three->value = 350;

    // Connect
    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;
    printf("Linked list: ");
    printList(head);

    // insert at begining
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->value=400;
    newNode->next=head;
    head=newNode;

    printf("\nLinked list after insertion: ");
    printList(head);
}
/* Output:

Linked list:  500.000000  200.000000  350.000000 
Linked list after insertion:  400.000000  500.000000  200.000000  350.000000

*/