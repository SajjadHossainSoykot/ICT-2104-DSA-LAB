#include <stdio.h>

int search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("Element %d found at index %d.\n", value, i);
            return i;
        }
    }
    printf("Element %d not found in the array.\n", value);
    return -1;
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
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value, newValue;

    printf("Original Array: ");
    printArray(arr, size);

    // Search for an element
    printf("Enter the element to search for: ");
    scanf("%d", &value);
    search(arr, size, value);

    //Update an element
    printf("Enter the element to update: ");
    scanf("%d", &value);
    int foundIndex = search(arr, size, value);

    if (foundIndex != -1)
    {
        printf("Enter the new value to update: ");
        scanf("%d", &newValue);
        arr[foundIndex]=newValue;
        printf("Updated Array: ");
        printArray(arr, size);
    }

    return 0;
}
/* Output:

Original Array: 10 20 30 40 50   
Enter the element to search for: 60
Element 60 not found in the array.
Enter the element to update: 30   
Element 30 found at index 2.        
Enter the new value to update: 60
Updated Array: 10 20 60 40 50

*/