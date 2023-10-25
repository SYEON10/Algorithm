#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    vector<vector<int>> DP(n, vector<int> (10, 0));

    DP[0] = vector<int>(10, 1);

    for(int i = 1; i < n; i++){
        for(int j = 9; j >= 0; j--){
            for(int k = j; k >= 0; k--){
                DP[i][j] += DP[i - 1][k] % 10007;
            }
        }
    }

    for(const auto& dp : DP[n-1]){
        count += dp;
    }

    cout << count % 10007;

    return 0;
}