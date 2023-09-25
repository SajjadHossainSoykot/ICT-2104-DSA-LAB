#include <iostream>
using namespace std;
#define MAX 10

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteFirst(int arr[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteMid(int arr[], int *size, int pos)
{
    if (pos < 0 && *size < pos)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    for (int i = pos; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteEnd(int arr[], int *size)
{
    (*size)--;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    display(arr, size);
    while (true)
    {
        int choice, pos;
        cout << "\nDelete at\n1. First\n2. Middle\n3. End\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (size<0)
        {
            cout << "Array is Empty. Can't Delete" << endl;
            return 0;
        }
        switch (choice)
        {
        case 1:
            deleteFirst(arr, &size);
            break;
        case 2:
            printf("Enter Position (0<position<%d) : ", size);
            cin >> pos;
            deleteMid(arr, &size, pos);
            break;
        case 3:
            deleteEnd(arr, &size);
            break;
        case 4:
            cout << "Exiting\n";
            return 0;
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
        cout << "Updated Array : ";
        display(arr, size);
    }
}