#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

//치즈 외부 공기 처리(D/BFS)
//치즈 녹이기 => 완탐 시뮬레이션 말고 가능한가?
//1회 완전탐색 비용 => 100 * 100
//최대 완탐 순회 횟수 => 50
//500'000 => 완탐 가능

//BFS를 두 개 두고
//치즈/외부공기
//=> 더 나은 선택 
//O(N*M) 시간복잡도
// ????????????????
// ????????????????
// 95% 틀렸습니다 tlqkf;;;
// 근데 왜 아까 시간초과 났지...? 날 수가 없는데......?
// => 아 이건 무한루프 돌았을 듯
// BFS 때문에 완탐이 더 빠를? 수가 ?
// V + E V = N * M, E = 4 * N * M 
// O(N * M)인데??

struct Point{
    int r, c;
};
struct DepthPoint{
    int r, c;
    int depth;
};

int n, m;
vector<vector<int>> board;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void AirBFS(int timer, queue<Point>& air, queue<DepthPoint>& cheese){
    while(!air.empty()){
        Point p = air.front();
        air.pop();

        for(int i = 0; i < 4; i++){
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if(nr < 0 || nr > n + 1 || nc < 0 || nc > m + 1) continue;

            if(board[nr][nc] == 0){
                air.push({nr, nc});
                board[nr][nc] = -1;
            }
            if(board[nr][nc] == 1){
                cheese.push({nr, nc, timer});
                board[nr][nc] = -1;
            }
        }
    }
}

//시작했을 때 depth와 다른 depth가 나올 시 종료
//이번에 녹인 치즈 수와 현재 depth 반환
pair<int, int> CheeseBFS(queue<Point>& air, queue<DepthPoint>& cheese){
    
    int startDepth = cheese.front().depth;
    int count = 0;

    while(!cheese.empty()){
        DepthPoint p = cheese.front();
        if(p.depth != startDepth) break;
        cheese.pop();

        count++;

        for(int i = 0; i < 4; i++){
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if(nr < 0 || nr > n + 1 || nc < 0 || nc > m + 1) continue;

            if(board[nr][nc] == 0){
                air.push({nr, nc});
                board[nr][nc] = -1;
            }
            if(board[nr][nc] == 1){
                cheese.push({nr, nc, startDepth + 1});
                board[nr][nc] = -1;
            }
        }
    }

    return {startDepth, count};
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    board.assign(n + 2, vector<int>(m + 2, 0));

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            cin >> board[r][c];
        }
    }

    //외부 공기 순회 -> 하면서 치즈 추가
    //치즈 순회하면서 외부 내부 공기 닿으면 air에 추가
    //air 순회 -> 하면서 치즈 추가
    //이미 녹인 치즈는 패스
    
    //치즈 BFS를 두 개 두기 vs depth 추적하기
    //추적하기.

    queue<Point> air;
    queue<DepthPoint> cheese;

    air.push({0, 0});
    board[0][0] = -1;

    int timer = 0;
    int count = 0;

    while(!air.empty() || !cheese.empty()){
        AirBFS(timer + 1, air, cheese);
        if(cheese.empty()) break;
        auto result = CheeseBFS(air, cheese);
        timer = result.first;
        count = result.second;
    }

    cout << timer << '\n' << count;

    return 0;
}