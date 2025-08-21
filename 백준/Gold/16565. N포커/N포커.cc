#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 10'007;

long long Combination(int n, int r){
    long long result = 1;

    for(int i = 1; i <= r; ++i){
        result *= (n - i + 1);
        result = result / i;
    }

    return result;
}

int Game(int n){
    long long result = 0;

    for(int i = 1; i <= 13; i++){
        if (n - 4 * i < 0) {
            break;
        }

        long long first = Combination(13, i);
        long long second = Combination(52 - i * 4, n - i * 4);
        long long multiple = (first * second) % MOD;


        if(i % 2 == 1) result = (result + multiple) % MOD;
        else result = (result - multiple + MOD) % MOD;
    }

    return result;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    if(n <= 3) cout << 0; //코너케이스
    else cout << Game(n);

    return 0;
}