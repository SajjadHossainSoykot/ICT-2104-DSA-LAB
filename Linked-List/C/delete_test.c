#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete the node at the specified position (0-based index)
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 0;

    // Traverse the linked list to find the node to be deleted
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If the node is not found at the specified position
    if (temp == NULL) {
        printf("Node at position %d not found.\n", position);
        return;
    }

    // Delete the node by updating the previous node's next pointer
    if (prev == NULL) {
        // Node to be deleted is the first node
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    // Free the memory occupied by the deleted node
    free(temp);
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create and insert 10 nodes into the linked list
    for (int i = 1; i <= 10; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original linked list: ");
    printLinkedList(head);

    // Delete the 5th node (index 4)
    deleteNode(&head, 4);
    printf("Linked list after deleting the 5th node: ");
    printLinkedList(head);

    // Delete the prev 9th node (index 7)
    deleteNode(&head, 7);
    printf("Linked list after deleting the 9th node: ");
    printLinkedList(head);

    // Free the memory occupied by the linked list nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
