#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v; // Declare a dynamic array (vector) of integers

    cout << "Enter values to add (0 to stop):\n";
    while (true)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        if (value == 0) break;
        
        v.push_back(value); // Add the element to the vector
    }

    cout << "Vector elements:\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " "; // Access and print elements using at() library function
    }
    cout << endl;

    return 0;
}
/* Output:

Enter values to add (0 to stop):
Enter value: 1
Enter value: 2
Enter value: 3
Enter value: 4 
Enter value: 0
Vector elements:
1 2 3 4 

*/