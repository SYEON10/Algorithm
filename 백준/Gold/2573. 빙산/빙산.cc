#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

//모든 타일에 대해 시간을 흐르게 하기(시뮬레이션)
//두 덩어리로 분리되었는지 확인(유니온 파인드)

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector<vector<int>> board;
vector<vector<int>> melt;
vector<vector<bool>> visited;
int check = 0;

void DFS(int r, int c){
    if(!visited[r][c]){
        check++;
        visited[r][c] = true;
    }
    else return;

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(board[nr][nc] == 0) continue;
        if(visited[nr][nc]) continue;
        DFS(nr, nc);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    board.assign(n + 2, vector<int>(m + 2, 0));
    visited.assign(n + 2, vector<bool>(m + 2, false));
    melt.assign(n + 2, vector<int>(m + 2, 0));

    int count = 0;
    int startPoint = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            cin >> board[r][c];
            if(board[r][c] != 0) {
                count++;
                startPoint = r * m + c;
            }
        }
    }

    int time = 0;
    while(true){
        time++;
        int turnCount = 0;
        int startR = -1;
        int startC = -1;

        //녹이기 => 순차적으로 녹아서 문제 발생. 한번에 녹여야 함...
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= m; c++){
                if(board[r][c] == 0) continue;
                int cnt = 0;
                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(board[nr][nc] == 0) cnt++;
                }
                if(board[r][c] - cnt > 0){
                    turnCount++;
                    startR = r;
                    startC = c;
                    melt[r][c] = cnt;
                }
                else melt[r][c] = board[r][c];
            }
        }
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= m; c++){
                visited[r][c] = false;
                if(board[r][c] == 0) continue;
                board[r][c] -= melt[r][c];
            }
        }

        if(turnCount == 0) {
            cout << 0;
            break;
        }

        check = 0;
        DFS(startR, startC);
        if(check < turnCount){
            cout << time;
            break;
        }
    }

    return 0;
}