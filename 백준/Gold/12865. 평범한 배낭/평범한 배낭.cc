#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> products(n + 1, {0, 0});
    vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));

    for(int i = 1; i <= n; i++){
        cin >> products[i].first >> products[i].second;
    }

    for(int i = 1; i <= n; i++){
        //이전 DP 복사
        for(int j = 1; j < products[i].first; j++){
            DP[i][j] = DP[i - 1][j];
        }
        //연산-업데이트
        for(int j = products[i].first; j <= k; j++){
            DP[i][j] = max(DP[i - 1][j], products[i].second + DP[i - 1][j - products[i].first]);
        }
    }

    cout << DP[n][k];

    return 0;
}
