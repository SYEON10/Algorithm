#include <iostream>
#include <vector>

using namespace std;

const int MOD = 9901;

int main()
{
    int n;
    cin >> n;

    vector<int> DP(n + 1, 0);
    vector<int> prefix(n + 1, 0);

    DP[0] = 0;
    prefix[0] = DP[0];

    int sum = 0;

    for(int i = 1; i <= n; i++){
        int val = DP[i - 1] + 1;
        if(i >= 2) val += 2 * prefix[i - 2];
        val %= MOD;

        DP[i] = val;
        prefix[i] = (prefix[i - 1] + DP[i]) % MOD;

        sum = (sum + 2 * DP[i]) % MOD;
    }

    cout << (sum + 1) % MOD << '\n';

    return 0;
}
