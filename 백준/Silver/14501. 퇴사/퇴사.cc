#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> board(n + 1, {0, 0});
    vector<int> DP(n + 1, 0); //각 날짜에 대한 최댓값

    for(int i = 0; i < n; i++){
        cin >> board[i].first >> board[i].second;
    }

    int maxVal = 0;

    for(int i = 0; i < n + 1; i++){
        DP[i] = max(maxVal, DP[i]);

        if(i + board[i].first < n + 1)
            DP[i + board[i].first] = max(DP[i + board[i].first], board[i].second + DP[i]);

        maxVal = max(maxVal, DP[i]);
    }

    cout << maxVal;

    return 0;
}