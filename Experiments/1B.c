#include <stdio.h>

#define MAX_SIZE 10

void insertFirst(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
}

void insertMid(int arr[], int *size, int value, int pos) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position. Cannot insert.\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void insertEnd(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, value, pos;

    while (1) {
        printf("\nArray: ");
        printArray(arr, size);
        printf("Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the middle\n");
        printf("3. Insert at the end\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(arr, &size, value);
                break;
            case 2:
                printf("Enter mid position to insert: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertMid(arr, &size, value, pos);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(arr, &size, value);
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n\n");
        }

        printf("Updated Array: ");
        printArray(arr, size);
    }
    return 0;
}
/* Output:


Array: 10 20 30 40 50     
Menu:
1. Insert at the beginning
2. Insert at the middle   
3. Insert at the end      
4. Exit
Enter your choice: 1      
Enter value: 5
Updated Array: 5 10 20 30 40 50 

Array: 5 10 20 30 40 50
Menu:
1. Insert at the beginning
2. Insert at the middle
3. Insert at the end
4. Exit
Enter your choice: 4
Exiting.

*/