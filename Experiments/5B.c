#include <stdio.h>
#include <stdlib.h>

struct Node // Define the structure for a singly linked list node
{
    int data;
    struct Node *next;
};

void checkEmpty(struct Node **head) //Checking Linked List Empty or Not
{
    if (*head == NULL)
    {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }
}

void deleteFromBeginning(struct Node **head)
{
    checkEmpty(head);
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromMiddle(struct Node **head, int position)
{
    checkEmpty(head);
    if (position < 0)
    {
        printf("Invalid position. Cannot delete.\n");
        return;
    }
    if (position == 0)
    {
        deleteFromBeginning(head);
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Invalid position. Cannot delete.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteFromEnd(struct Node **head)
{
   checkEmpty(head);

    struct Node *current = *head;
    struct Node *prev = NULL;

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

void printLinkedList(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{   
    // Creating Nodes and memory Allocation
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *one = malloc(sizeof(struct Node));
    struct Node *two = malloc(sizeof(struct Node));
    struct Node *three = malloc(sizeof(struct Node));
    struct Node *four = malloc(sizeof(struct Node));

    // Asign Values
    one->data = 10;
    two->data = 20;
    three->data = 30;
    four->data = 40;

    // Connect
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;
    head = one;

    // Print the original linked list
    printf("Linked List: ");
    printLinkedList(head);

    int choice, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Delete from the beginning\n");
        printf("2. Delete from the middle\n");
        printf("3. Delete from the end\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deleteFromBeginning(&head);
            break;
        case 2:
            printf("Enter the position (0-based) to delete: ");
            scanf("%d", &position);
            deleteFromMiddle(&head, position);
            break;
        case 3:
            deleteFromEnd(&head);
            break;
        case 4:
            printf("Exiting.\n");
            return 0;
        default:
            printf("Invalid choice.\n\n");
        }

        // Print the updated linked list
        printf("Updated Linked List: ");
        printLinkedList(head);
    }

    return 0;
}
/* Output:

Linked List: 10 20 30 40 

Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 1
Updated Linked List: 20 30 40 

Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 3
Updated Linked List: 20 30 

Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 2
Enter the position (0-based) to delete: 1
Updated Linked List: 20 

Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 1
Updated Linked List: 

Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 1
Linked list is empty. Cannot delete.

*/