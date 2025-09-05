#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

//전체 보드 1회 순회 - 1'000'000
//최대 시간복잡도 O(nlogn)

//BackTracking
//거리와 무관하게 마구잡이로 도착하기 때문에
//벽을 부숨 여부/경로에 따라서 경우의 수 계속 증가 => 불가능

//BFS
//무조건 먼저 visit 됐던 곳을 기준으로 삼기 때문에 이미 방문한 곳에 다시 돌아가서 방문할 필요 X

int n, m;
int board[1000][1000];
bool visited[1000][1000][2];
int result = INT32_MAX;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int BFS(){
    queue<tuple<int, int, bool, int>> q;
    q.push(make_tuple(0, 0, false, 1));
    visited[0][0][0] = true;

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int r = get<0>(p);
        int c = get<1>(p);
        bool isBroken = get<2>(p);
        int count = get<3>(p);

        if(r == n - 1 && c == m - 1){
            return count;
        }

        for(int i = 0; i < 4; i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;

            if(nr >= n || nr < 0 || nc >= m || nc < 0){
                continue;
            }

            if(board[nr][nc] == 1){
                if(isBroken) continue;
                if(visited[nr][nc][1]) continue;
                visited[nr][nc][1] = true;
                q.push(make_tuple(nr, nc, true, count + 1));
            }
            else{
                if(visited[nr][nc][isBroken]) continue;
                visited[nr][nc][isBroken] = true;
                q.push(make_tuple(nr, nc, isBroken, count + 1));
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    for(int r = 0; r < n; r++){
        string input;
        cin >> input;
        for(int c = 0; c < m; c++){
            board[r][c] = input[c] - '0';
        }
    } 

    result = BFS();

    cout << result;

    return 0;
}