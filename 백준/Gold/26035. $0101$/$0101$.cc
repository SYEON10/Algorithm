#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

//조합론
//거듭제곱을 이용한 분할정복

ll modpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    long long n, m;
    cin >> n >> m;

    if(m > n) swap(m, n);

    long long result = 0;

    n %= MOD - 1;
    m %= MOD - 1;

    result = ((modpow(2, n) + modpow(2, m)) % MOD + MOD - 2) % MOD;

    cout << result;

    return 0;
}