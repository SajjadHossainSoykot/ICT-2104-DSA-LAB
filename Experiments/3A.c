#include <stdio.h>
#define MAX_SIZE 10

void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    int position, value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    printf("Enter the position to insert (0 <= position <= %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot insert.\n");
        return;
    }
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the value at the specified position
    arr[position] = value;
    (*size)++;
}

void deleteElement(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    int position;
    printf("Enter the position to delete (0 <= position < %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Invalid position. Cannot delete.\n");
        return;
    }
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;    
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice;

    while (1) {
        printf("\nOriginal Array: ");
        printArray(arr,size);
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertElement(arr, &size);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n\n");
        }
        printf("Updated Array: ");
        printArray(arr,size);
    }
    return 0;
}
/* Output:


Original Array: 10 20 30 40 50 60 
Menu:
1. Insert an element
2. Delete an element
3. Exit
Enter your choice: 1
Enter the value to insert: 70
Enter the position to insert (0 <= position <= 6): 6
Updated Array: 10 20 30 40 50 60 70 

Original Array: 10 20 30 40 50 60 70
Menu:
1. Insert an element
2. Delete an element
3. Exit
Enter your choice: 2
Enter the position to delete (0 <= position < 7): 6
Updated Array: 10 20 30 40 50 60 

Original Array: 10 20 30 40 50 60
Menu:
1. Insert an element
2. Delete an element
3. Exit
Enter your choice: 3
Exiting.

*/