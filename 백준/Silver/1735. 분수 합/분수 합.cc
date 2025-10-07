#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int up = a * d + c * b;
    int down = b * d;
    int gcd = __gcd(up, down);

    cout << up/gcd << ' ' << down/gcd;

    return 0;
}