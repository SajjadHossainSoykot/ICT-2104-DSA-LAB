#include <stdio.h>
#define MAX_SIZE 10

void deleteFirst(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteMid(int arr[], int *size, int pos)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *size)
    {
        printf("Invalid position. Cannot delete.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteEnd(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    (*size)--;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, pos;

    while (1)
    {
        printf("\nArray: ");
        printArray(arr, size);
        printf("Menu:\n");
        printf("1. Delete from the beginning\n");
        printf("2. Delete from the middle\n");
        printf("3. Delete from the end\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deleteFirst(arr, &size);
            break;
        case 2:
            printf("Enter mid position to delete: ");
            scanf("%d", &pos);
            deleteMid(arr, &size, pos);
            break;
        case 3:
            deleteEnd(arr, &size);
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


Array: 10 20 30 40 50 60 70 
Menu:
1. Delete from the beginning
2. Delete from the middle   
3. Delete from the end      
4. Exit
Enter your choice: 3
Updated Array: 10 20 30 40 50 60 

Array: 10 20 30 40 50 60         
Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 3
Updated Array: 10 20 30 40 50 

Array: 10 20 30 40 50
Menu:
1. Delete from the beginning
2. Delete from the middle
3. Delete from the end
4. Exit
Enter your choice: 4
Exiting.

*/