#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        int gcd = 1;
        for(int i = 1; i <= 1000; i++){
            if(a % i == 0 && b % i == 0){
                gcd = i;
            }
        }

        int lcm = (a * b) / gcd;
        cout << lcm << ' ' << gcd << '\n';
    }

    return 0;
}