#include <iostream>
using namespace std;
template <typename T>
T large(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    double x, y;
    cin >> a >> b;
    cin >> x >> y;
    cout << "Largest int = " << large<int>(a, b) << endl;
    cout << "Largest float = " << large<double>(x, y) << endl;
}