#include <iostream>
using namespace std;

// Function template to find the largest number
template <typename T>
T findLargest(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Declare variables of the desired data type
    int a, b;
    double x, y;

    // Input values from the user
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Enter two floating-point numbers: ";
    cin >> x >> y;

    // calling with int parameters
    int largestInt = findLargest<int>(a, b);

    // calling with double parameters
    double largestDouble = findLargest<double>(x, y);

    // Display the results
    cout << "The largest integer: " << largestInt << endl;
    cout << "The largest floating-point number: " << largestDouble << endl;

    return 0;
}
/* Output:

Enter two integers: 5 10
Enter two floating-point numbers: 5.1 1.5
The largest integer: 10
The largest floating-point number: 5.1

*/