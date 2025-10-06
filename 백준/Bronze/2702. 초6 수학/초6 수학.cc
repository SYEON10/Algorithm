#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//BOJ 2702

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        if(a < b) swap(a, b);
        int gcd = GCD(a, b);
        int lcm = (a * b) / gcd;
        cout << lcm << ' ' << gcd << '\n';
    }

    return 0;
}