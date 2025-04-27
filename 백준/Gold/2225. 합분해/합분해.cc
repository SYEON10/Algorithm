#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> DP(k + 1, vector<int>(n + 1));

    DP[0][0] = 1;

    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int x = 0; x <= j; x++){
                DP[i][j] += DP[i - 1][j - x];
                DP[i][j] %= MOD;
            }
        }
    }

    cout << DP[k][n];

    return 0;
}