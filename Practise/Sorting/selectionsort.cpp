#include <iostream>
using namespace std;
#define MAX = 10;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n)
{
    int minid;
    for (int i = 0; i < n; i++)
    {
        minid = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j]<arr[minid])
                minid = j;
        }
        swap(&arr[i], &arr[minid]);
    }
}

int main()
{
    int arr[] = {5, 2, 4, 1 , 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);
}