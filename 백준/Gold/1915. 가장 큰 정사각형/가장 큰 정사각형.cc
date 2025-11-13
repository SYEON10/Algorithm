#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    for(int r = 1; r <= n; r++){
        string line;
        cin >> line;
        for(int c = 0; c < m; c++){
            board[r][c + 1] = line[c] - '0';
        }
    }

    int max_value = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            if(board[r][c] == 0) continue;
            board[r][c] += min(min(board[r - 1][c], board[r][c - 1]), board[r - 1][c - 1]);
            max_value = max(max_value, board[r][c]);
        }
    }

    cout << max_value * max_value;

    return 0;
}