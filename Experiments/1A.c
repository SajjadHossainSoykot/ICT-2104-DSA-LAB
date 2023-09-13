#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        int min_idx = j;
        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] < arr[min_idx]) min_idx = i;
        }
        swap(&arr[min_idx], &arr[j]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i) printf("%d  ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {20, 12, 10, 15, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
}
/* Output:

20  12  10  15  2
Sorted Array:
2  10  12  15  20

*/