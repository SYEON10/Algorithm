#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int board[500][500];
int DP[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int DFS(int r, int c){
    if(DP[r][c] > 0) return DP[r][c];
    int count = 0;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if(board[nr][nc] <= board[r][c]) continue;

        count = max(count, DFS(nr, nc));
    }

    return DP[r][c] = count + 1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> board[r][c];
        }
    }

    int res = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            res = max(res, DFS(r, c));
        }
    }

    cout << res;

    return 0;
}