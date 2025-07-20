#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};

int n, m;
vector<vector<int>> matrix;
vector<vector<int>> DP;

//r, c부터 n, m까지 가는 방법
//DP[r][c] = 메모이제이션
int dfs(int r, int c){
    if(r == n && c == m){
        return 1;
    }
    if(DP[r][c] != -1){
        return DP[r][c];
    }

    DP[r][c] = 0;
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(matrix[nr][nc] >= matrix[r][c]) continue;

        DP[r][c] += dfs(nr, nc);
    }

    return DP[r][c];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    matrix.assign(n + 2, vector<int>(m + 2, INT32_MAX));
    DP.assign(n + 2, vector<int>(m + 2, -1));

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            cin >> matrix[r][c];
        }
    }

    cout << dfs(1, 1);

    return 0;
}