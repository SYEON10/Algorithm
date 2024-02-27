#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<vector<int>> RGB(n+1, vector<int>(3));

    vector<vector<int>> DP(n+1, vector<int>(3));

    for(int i = 1; i <= n; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }

    DP[1][0] = RGB[1][0];
    DP[1][1] = RGB[1][1];
    DP[1][2] = RGB[1][2];

    for(int i = 1; i <= n; i++){
        DP[i][0] = min(DP[i-1][1]+RGB[i][0], DP[i-1][2]+RGB[i][0]);
        DP[i][1] = min(DP[i-1][0]+RGB[i][1], DP[i-1][2]+RGB[i][1]);
        DP[i][2] = min(DP[i-1][1]+RGB[i][2], DP[i-1][0]+RGB[i][2]);
    }

    int result = DP[n][0] > DP[n][1] ? DP[n][1] : DP[n][0];
    result = result > DP[n][2] ? DP[n][2] : result;

    cout << result;

    return 0;
}