#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> matrix(n);
    vector<vector<int>> DP(n, vector<int>(n, INT32_MAX)); //필요한 곱셈 연산 최솟값

    for(int i = 0; i < n; i++){
        cin >> matrix[i].first >> matrix[i].second;
        DP[i][i] = 0;
    }

    for(int len = 1; len < n; len++){
        for(int i = 0; i < n - len; i++){
            int j = i + len;
            for(int k = i; k < j; k++){
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
            }
        }
    }

    cout << DP[0][n-1];

    return 0;
}