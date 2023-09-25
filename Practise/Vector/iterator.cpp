#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &v)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Original Vector: ";
    display(v);

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        *it = *it * 2;
    }
    cout << "Modified Vector: ";
    display(v);
}