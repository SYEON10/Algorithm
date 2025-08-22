#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

//최댓값일 때 모음 - 최솟값일 때 모음
//조합일 필요 없음 따로 계산해도 문제X

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

    int n;
    cin >> n;
    vector<int> foods(n, 0);
    
    for(int i = 0; i < n; i++){
        cin >> foods[i];
    }

    if(n == 1){ //코너케이스
        cout << 0;
        return 0;
    }

    sort(foods.begin(), foods.end());

    ll result = 0;

    for(int i = 0; i < n; i++){
        ll max_value = modpow(2, i);
        ll min_value = modpow(2, n - i - 1);
        ll value = (max_value - min_value + MOD) % MOD;
        result = (result + foods[i] * value) % MOD;
    }

    cout << result;

    return 0;
}