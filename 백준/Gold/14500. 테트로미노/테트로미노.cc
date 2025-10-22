#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

//완탐

const int INF = 1001;

int n, m;
int board[501][501];
typedef pair<int, int> point;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int max_value = 0;

void DFS(int value, int count, int r, int c, int prevR, int prevC){
    if(count == 4){
        max_value = max(max_value, value);
        return;
    }

    if(count == 2){
        int sum = value;
        int min_value = INF;
        int passCount = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) {
                passCount++;
                continue;
            }
            if(nr == prevR && nc == prevC) {
                passCount++;
                continue;
            }

            min_value = min(min_value, board[nr][nc]);
            sum += board[nr][nc];
        }

        if(passCount == 2) {
            max_value = max(max_value, sum);
        }
        if(passCount == 1){
            max_value = max(max_value, sum - min_value);
        }
    }

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(nr == prevR && nc == prevC) continue;

        DFS(value + board[nr][nc], count + 1, nr, nc, r, c);
    }
}

void Checker(int r, int c){
    DFS(board[r][c], 1, r, c, -1, -1);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            Checker(r, c);
        }
    }

    cout << max_value;

    return 0;
}