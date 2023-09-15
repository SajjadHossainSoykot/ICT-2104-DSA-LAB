#include <iostream>
using namespace std;

// Define a class template for adding two numbers
template <typename T>
class Adder {
private:
    T result;

public:
    // Constructor to initialize the result to zero
    Adder() : result(0) {}

    // Member function to add two numbers
    void add(T a, T b) {
        result = a + b;
    }

    // Member function to retrieve the result
    T getResult() {
        return result;
    }
};

int main() {
    // Create instances of the Add class template for int and double
    Adder<int> intAdd;
    Adder<double> doubleAdd;

    // Add two integers
    intAdd.add(5, 7);

    // Add two floating-point numbers
    doubleAdd.add(3.14, 2.71);

    // Display the results
    cout << "Sum of two integers: " << intAdd.getResult() << endl;
    cout << "Sum of two floating-point numbers: " << doubleAdd.getResult() << endl;

    return 0;
}
/* Output:

Sum of two integers: 12
Sum of two floating-point numbers: 5.85

*/s