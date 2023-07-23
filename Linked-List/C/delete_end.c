// Linked list insertion at begining in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node
{
    int value;
    struct node *next;
};

// Print the linked list
void printList(struct node *p)
{
    while (p != NULL)
    {
        printf(" %d ", p->value);
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
    struct node *four = NULL;

    // Allocation
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));

    // Asign
    one->value = 500;
    two->value = 200;
    three->value = 350;
    four->value = 150;

    // Connect
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;
    printf("Linked list: ");
    printList(head);

    // delete at middle
    struct node *temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=NULL;   
    
    printf("\nLinked list after delete at end: ");
    printList(head);
}
/* Output:

Linked list:  500  200  350  150 
Linked list after delete at end:  500  200  350

*/