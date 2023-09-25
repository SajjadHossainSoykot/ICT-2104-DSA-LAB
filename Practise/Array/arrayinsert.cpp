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

void insertFirst(int arr[], int *size, int value)
{
    for (int i = *size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
}

void insertMid(int arr[], int *size, int value, int pos)
{
    if (pos < 0 && *size < pos)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    for (int i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void insertLast(int arr[], int *size, int value)
{
    arr[*size] = value;
    (*size)++;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    display(arr, size);
    while (true)
    {
        int choice, value, pos;
        cout << "\nInsert at\n1. First\n2. Middle\n3. End\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (size >= MAX)
        {
            cout << "Array is Full. Can't Insert" << endl;
            return 0;
        }
        cout << "Enter Value: ";
        cin >> value;
        switch (choice)
        {
        case 1:
            insertFirst(arr, &size, value);
            break;
        case 2:
            printf("Enter Position (0<position<%d) : ", size);
            cin>>pos;
            insertMid(arr, &size, value, pos);
            break;
        case 3:
            insertLast(arr, &size, value);
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