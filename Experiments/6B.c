#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data)
{
    // Creating New Node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // Inserting
    newNode->next = *head;
    *head = newNode;
}

void insertAtMiddle(struct Node **head, int position, int data)
{
    if (position < 0)
    {
        printf("Invalid position. Cannot insert.\n");
        return;
    }

    if (position == 0)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;
    int count = 0;

    // Traverse to find the previous node of the target position
    while (current != NULL && count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL && count != position)
    {
        printf("Invalid position. Cannot insert.\n");
        return;
    }

    // Creating New Node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // Inserting between prev and current
    prev->next = newNode;
    newNode->next = current;
}

void insertAtEnd(struct Node **head, int data)
{
    // Creating New Node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        // If the linked list is empty, set the head to the new node
        *head = newNode;
        return;
    }

    // Traverse to find the last node
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    // Update the last node's next pointer to point to the new node
    current->next = newNode;
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

    // Asign Values
    one->data = 10;
    two->data = 20;
    three->data = 30;

    // Connect
    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;

    // Print the original linked list
    printf("Linked List: ");
    printLinkedList(head);

    int choice, position, data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the middle\n");
        printf("3. Insert at the end\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice != 4)
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
        }

        switch (choice)
        {
        case 1:
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter position (0-based) to insert: ");
            scanf("%d", &position);
            insertAtMiddle(&head, position, data);
            break;
        case 3:
            insertAtEnd(&head, data);
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

Linked List: 10 20 30     

Menu:
1. Insert at the beginning
2. Insert at the middle   
3. Insert at the end      
4. Exit
Enter your choice: 1      
Enter data to insert: 5
Updated Linked List: 5 10 20 30 

Menu:
1. Insert at the beginning
2. Insert at the middle
3. Insert at the end
4. Exit
Enter your choice: 3
Enter data to insert: 40
Updated Linked List: 5 10 20 30 40 

Menu:
1. Insert at the beginning
2. Insert at the middle
3. Insert at the end
4. Exit
Enter your choice: 2
Enter data to insert: 25
Enter position (0-based) to insert: 3
Updated Linked List: 5 10 20 25 30 40 

Menu:
1. Insert at the beginning
2. Insert at the middle
3. Insert at the end
4. Exit
Enter your choice: 4
Exiting.

*/