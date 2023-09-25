#include <iostream>
using namespace std;
template <typename T>
class adder
{
private:
    T result;

public:
    adder() : result(0) {}
    void add(T a, T b)
    {
        result = a+b;
    }
    T get_result()
    {
        return result;

    }
};

int main() {
    // Create instances of the Add class template for int and double
    adder<int> intAdd;
    adder<double> doubleAdd;

    // Add two integers
    intAdd.add(5, 7);

    // Add two floating-point numbers
    doubleAdd.add(3.14, 2.71);

    // Display the results
    cout << "Sum of two integers: " << intAdd.get_result() << endl;
    cout << "Sum of two floating-point numbers: " << doubleAdd.get_result() << endl;

    return 0;
}