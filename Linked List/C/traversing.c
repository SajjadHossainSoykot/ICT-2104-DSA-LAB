// Linked list traversal in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
 float value;
  struct node *next;
};

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%f ", p->value);
    p = p->next;
  }
  printf("\n");
}

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  // Assign value values
  one->value = 100.40;
  two->value = 20.89;
  three->value = 500.01;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printf("Traversing Linked List: ");
  printLinkedlist(head);
  return 1;
}
/* Output:

Traversing Linked List: 100.400002 20.889999 500.010010 

*/