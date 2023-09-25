#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

void update(vector<int> &v, int index)
{
    if (index < 0 && index >= v.size())
    {
        cout << "Invalid Index. Can't Update";
        return;
    }
    int newValue;
    cout << "Enter New Value: ";
    cin >> newValue;
    v.at(index) = newValue;
    cout << "Value updated\n";
}

void deletion(vector<int> &v)
{
    if (v.empty())
    {
        cout << "Empty Vector. Can't Delete\n";
        return;
    }
    cout<<"Enter position to delete : ";
    int position;
    cin>>position;
    for (int i = position; i < v.size()-1; i++)
    {
        v.at(i) = v.at(i+1);
    }
    v.pop_back();
    cout << "Value Deleted\n";
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Original Vector: ";
    display(v);

    while (true)
    {
        int choice, index;
        cout << "\nMenu:\n1. Update\n2. Delete\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Index to Update : ";
            cin>>index;
            update(v,index);
            break;
        case 2:
            deletion(v);
            break;
        case 3:
            cout << "Exiting\n";
            return 0;
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
        cout << "Updated Vector : ";
        display(v);
    }
    display(v);
}