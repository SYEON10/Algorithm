#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout << fixed;
    cout.precision(9);
    cout << a / b;

    return 0;
}