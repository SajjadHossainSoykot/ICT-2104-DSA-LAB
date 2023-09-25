#include <iostream>
using namespace std;
#define MAX = 10;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 4, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);
}