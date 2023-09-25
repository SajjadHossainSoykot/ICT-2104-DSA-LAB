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

void insert(int arr[], int *size)
{
    if (*size >= MAX)
    {
        cout << "Array is Full. Can't Insert" << endl;
        return;
    }
    int value, pos;
    cout << "Enter Value: ";
    cin >> value;
    printf("Enter Position to Insert (0<=position<=%d) : ", *size);
    cin >> pos;
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

void deletion(int arr[], int *size)
{
    if (size < 0)
    {
        cout << "Array is Empty. Can't Delete" << endl;
        return;
    }
    printf("Enter Position to Delete (0<=position<%d) : ", *size);
    int pos;
    cin >> pos;
    if (pos < 0 && *size <= pos)
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    display(arr, size);
    while (true)
    {
        int choice;
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert(arr, &size);
            break;
        case 2:
            deletion(arr, &size);
            break;
        case 3:
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