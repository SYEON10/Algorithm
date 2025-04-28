#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    //0 가로 1 세로 2 대각선
    vector<vector<vector<int>>> DP(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            cin >> matrix[r][c];
        }
    }

    DP[1][2][0] = 1;

    for(int r = 1; r <= n; r++){
        for(int c = 2; c <= n; c++){
            if(matrix[r][c] == 1) continue;

            DP[r][c][0] += DP[r][c - 1][0] + DP[r][c - 1][2];
            DP[r][c][1] += DP[r - 1][c][1] + DP[r - 1][c][2];

            if(!(matrix[r][c-1] == 1 || matrix[r-1][c] == 1)){
                DP[r][c][2] += DP[r - 1][c - 1][0] + DP[r - 1][c - 1][1] + DP[r - 1][c - 1][2];
            }
        }
    }

    cout << DP[n][n][0] + DP[n][n][1] + DP[n][n][2];

    return 0;
}