#include <stdio.h>

void printArray(int *ptr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *ptr = arr; // Declare a pointer and assign the array's address

    printf("Original Array: ");
    printArray(arr,n); 

    // Use the pointer to modify elements in the array
    ptr[1] = 99;
    ptr[3] = 77;

    printf("Modified Array: ");
    printArray(ptr,n); //Using Pointer to print array

    return 0;
}
/* Output:

Original Array: 10 20 30 40 50 
Modified Array: 10 99 30 77 50

*/
