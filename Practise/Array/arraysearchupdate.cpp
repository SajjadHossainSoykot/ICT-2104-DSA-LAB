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

int search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            cout << "Value Found at Index : " << i << endl;
            return i;
        }
    }
    cout << "Value Not Found" << endl;
    return -1;
}

void update(int arr[], int index)
{
    int newValue;
    cout << "Enter New Value: ";
    cin >> newValue;
    arr[index] = newValue;
    cout << "Value Updated" << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array : ";
    display(arr, size);

    int foundIndex = -1; // Declare foundIndex here and initialize it to -1

    while (true)
    {
        int choice;
        cout << "\nMenu:\n1. Search\n2. Update\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int value;
        switch (choice)
        {
        case 1:
            cout << "Enter Value to Search: ";
            cin >> value;
            search(arr, size, value);
            break;
        case 2:
            cout << "Enter Value to update: ";
            cin >> value;
            foundIndex = search(arr, size, value); // Assign foundIndex here
            if (foundIndex != -1)
            {
                update(arr, foundIndex);
                cout << "Updated Array : ";
                display(arr, size);
            }
            else
            {
                cout << "Can't Update\n";
            }
            break;
        case 3:
            cout << "Exiting\n";
            return 0;
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}
