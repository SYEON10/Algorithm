#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> table(3, 0);
    //DP[i] = 해당 줄에서의 최대/최소 점수
    vector<vector<int>> max_DP(2, vector<int>(3, 0));
    vector<vector<int>> min_DP(2, vector<int>(3, 0));
    
    //DP[i][j] = max(DP[i - 1] + table[j], )
    for(int r = 1; r <= n; r++){
        for(int c = 0; c < 3; c++){
            cin >> table[c];
        }
        max_DP[1][0] = max(max_DP[0][0], max_DP[0][1]) + table[0];
        max_DP[1][1] = max(max_DP[0][0], max(max_DP[0][1], max_DP[0][2])) + table[1];
        max_DP[1][2] = max(max_DP[0][1], max_DP[0][2]) + table[2];

        min_DP[1][0] = min(min_DP[0][0], min_DP[0][1]) + table[0];
        min_DP[1][1] = min(min_DP[0][0], min(min_DP[0][1], min_DP[0][2])) + table[1];
        min_DP[1][2] = min(min_DP[0][1], min_DP[0][2]) + table[2];

        max_DP[0] = max_DP[1];
        min_DP[0] = min_DP[1];
    }

    cout << max(max_DP[0][0], max(max_DP[0][1], max_DP[0][2])) << ' ';
    cout << min(min_DP[0][0], min(min_DP[0][1], min_DP[0][2]));

    return 0;
}