#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int board[n + 1][n + 1];
    int DP[3][n + 1][n + 1]; //0 - 가로, 1 - 세로, 2 - 대각선

    memset(board, 0, sizeof(board));
    memset(DP, 0, sizeof(DP));

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            cin >> board[r][c];
        }
    }

    DP[0][1][2] = 1;

    for(int r = 1; r <= n; r++){
        for(int c = 2; c <= n; c++){
            if(board[r][c] == 1) continue;
            if(r == 1 && c == 2) continue;
            DP[0][r][c] = DP[0][r][c - 1] + DP[2][r][c - 1];
            DP[1][r][c] = DP[1][r - 1][c] + DP[2][r - 1][c];
            if(board[r - 1][c] == 1 || board[r][c - 1] == 1) continue;
            DP[2][r][c] = DP[0][r - 1][c - 1] + DP[1][r - 1][c - 1] + DP[2][r - 1][c - 1];
        }
    }

    cout << DP[0][n][n] + DP[1][n][n] + DP[2][n][n];

    return 0;
}