#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

// Function to update a vector element at a given index
void updateElement(vector<int> &v, int index, int newValue)
{
    if (index >= 0 && index < v.size())
    {
        v.at(index) = newValue;
        cout << "Element updated.\n";
    }
    else cout << "Invalid index. Element not updated.\n";
}

// Function to delete the last element from the vector
void deleteLastElement(vector<int> &v)
{
    if (!v.empty())
    {
        v.pop_back();
        cout << "Last element deleted.\n";
    }
    else cout << "Vector is empty. Cannot delete.\n";
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50}; // Declare a dynamic array (vector) of integers

    printf("Initial Vector: ");
    printVector(v);

    int choice, index, newValue;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Update element\n";
        cout << "2. Delete last element\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the index of the element to update: ";
            cin >> index;
            cout << "Enter the new value: ";
            cin >> newValue;
            updateElement(v, index, newValue);

            break;

        case 2:
            deleteLastElement(v);
            break;

        case 3:
            cout << "Exiting.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
        printf("Updated Vector: ");
        printVector(v);
    }
    return 0;
}
/* Output:

Initial Vector: 10 20 30 40 50 

Menu:
1. Update element
2. Delete last element
3. Exit
Enter your choice: 1
Enter the index of the element to update: 1
Enter the new value: 25
Element updated.
Updated Vector: 10 25 30 40 50

Menu:
1. Update element
2. Delete last element
3. Exit
Enter your choice: 2
Last element deleted.
Updated Vector: 10 25 30 40

Menu:
1. Update element
2. Delete last element
3. Exit
Enter your choice: 3
Exiting.

*/