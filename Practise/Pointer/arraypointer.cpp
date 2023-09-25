#include <iostream>
using namespace std;

void display(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr = arr;

    cout << "Original Array : ";
    display(ptr, size);

    ptr[1] = 6;
    ptr[3] = 9;

    cout << "Updated Array : ";
    display(ptr, size);
}