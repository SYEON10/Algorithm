#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_WALL = 3;
const int MAX_LENGTH = 8;

int n, m;
int board[MAX_LENGTH][MAX_LENGTH];
int result = 0;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int wall_count = MAX_WALL;

typedef pair<int, int> point;

int Simulate(){
    int count = 0;

    queue<point> q;
    bool visited[n][m];
    memset(visited, false, sizeof(visited));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(board[r][c] == 2){
                q.push({r, c});
                count++;
                visited[r][c] = true;
            }
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;

            if(board[nr][nc] == 0 && !visited[nr][nc]){
                q.push({nr, nc});
                count++;
                visited[nr][nc] = true;
            }
        }
    }

    return (n * m) - (count + wall_count);
}

void BackTracking(int count, int start){
    if(count == 3){
        result = max(result, Simulate());
        return;
    }

    for(int idx = start; idx < n * m; idx++){
        int r = idx / m;
        int c = idx % m;

        if(board[r][c] == 0){
            board[r][c] = 1;
            BackTracking(count + 1, idx + 1);
            board[r][c] = 0;
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
            if(board[r][c] == 1){
                wall_count++;
            }
        }
    }

    BackTracking(0, 0);

    cout << result;

    return 0;
}