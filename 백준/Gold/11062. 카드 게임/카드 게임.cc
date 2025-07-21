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
        int n;
        cin >> n;

        vector<int> cards(n);
        //DP[l][r] = 근우가 l부터 r까지의 구간에서 가져갈 수 있는 최댓값
        vector<vector<int>> DP(n, vector<int>(n));
        vector<int> prefix_sum(n, 0);

        for(int i = 0; i < n; i++){
            cin >> cards[i];

            DP[i][i] = cards[i];
            prefix_sum[i] = prefix_sum[i - 1] + cards[i];
        }

        for(int len = 1; len < n; len++){
            for(int l = 0; l < n - len; l++){
                int r = l + len;
                DP[l][r] = max(prefix_sum[r - 1] - prefix_sum[l - 1] - DP[l][r - 1] + cards[r], prefix_sum[r] - prefix_sum[l] - DP[l + 1][r] + cards[l]);
            }
        }

        cout << DP[0][n - 1] << '\n';
    }

    return 0;
}