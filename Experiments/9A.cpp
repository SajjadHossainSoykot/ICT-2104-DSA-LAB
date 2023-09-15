#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // Define a vector container and populate it with values
    vector<int> numbers;
    for (int i = 1; i <= 5; i++)
    {
        numbers.push_back(i);
    }

    //Display Initial
    cout << "Initial Elements: ";
    printVector(numbers);

    // Create an iterator for the vector
    vector<int>::iterator it;

    // Use the iterator to manipulate the elements (e.g., double each element)
    for (it = numbers.begin(); it != numbers.end(); ++it)
    {
        *it = *it * 2;
    }

    //Display Modified
    cout << "Modified Elements: ";
    printVector(numbers);
    return 0;
}
/* Output:

Initial Elements: 1 2 3 4 5 
Modified Elements: 2 4 6 8 10

*/