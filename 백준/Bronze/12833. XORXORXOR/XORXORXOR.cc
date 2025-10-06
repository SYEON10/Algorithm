#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    if(c % 2 == 0){
        cout << a;
    }
    else{
        cout << (a ^ b);
    }

    return 0;
}