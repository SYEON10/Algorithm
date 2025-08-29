#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

//N, M이 매우 작은 시뮬레이션 문제

//1. 완전탐색 - 모든 CCVT 방향 경우의 수를 시뮬레이션 -> 4의 8승 => 2의 16승 : 가능
//2. ...?

struct point{
    int r;
    int c;
    int type;
    int dir;
};

int n, m;
vector<vector<int>> board;
vector<point> cctv;
int result = INT32_MAX;
int obj_count = 0;

//0 1 2 3
int Direction(int pr, int pc, int dir, vector<vector<int>>& b){
    int count = 0;
    int dr = 0, dc = 0;
    if(dir % 2 == 0) dr = dir - 1;
    else dc = dir - 2;

    for(int r = pr, c = pc; r < n && r >= 0 && c < m && c >= 0; r += dr, c += dc){
        if(b[r][c] == 6) break;
        if(b[r][c] == 0) {
            count++;
            b[r][c] = -1;
        }
    }
    return count;
}

//시뮬레이션
int Simulation(){
    vector<vector<int>> b = board;
    int count = 0;
    for(point p : cctv){
        switch(p.type){
            case 1:
                count += Direction(p.r, p.c, p.dir, b);
                break;
            case 2:
                count += Direction(p.r, p.c, p.dir, b);
                count += Direction(p.r, p.c, (p.dir + 2) % 4, b);
                break;
            case 3:
                count += Direction(p.r, p.c, p.dir, b);
                count += Direction(p.r, p.c, (p.dir + 1) % 4, b);
                break;
            case 4:
                count += Direction(p.r, p.c, p.dir, b);
                count += Direction(p.r, p.c, (p.dir + 1) % 4, b);
                count += Direction(p.r, p.c, (p.dir + 2) % 4, b);
                break;
            case 5:
                count += Direction(p.r, p.c, p.dir, b);
                count += Direction(p.r, p.c, (p.dir + 1) % 4, b);
                count += Direction(p.r, p.c, (p.dir + 2) % 4, b);
                count += Direction(p.r, p.c, (p.dir + 3) % 4, b);
                break;
        }
    }
    return n * m - (count + obj_count);
}

//모든 CCTV에 대한 방향 경우의 수 계산
void BackTracking(int c){
    if(c == cctv.size()){
        result = min(result, Simulation());
        return;
    }

    for(int i = 0; i <= 3; i++){
        cctv[c].dir = i;
        BackTracking(c + 1);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    //완탐 가능은 하지만 최적화로 풀랬으니 완탐은 X
    //CCTV의 방향을 결정 -> 사각지대를 최소화
    //모든 경우의 수에 대해서 탐색...
    //모든 CCTV에 대해서 방향을 설정 후 시뮬레이션?
    
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> board[r][c];
            if(board[r][c] != 0){
                obj_count++;
            }
            if(board[r][c] != 6 && board[r][c] != 0){
                cctv.push_back(point{r, c, board[r][c], 0});
            }
        }
    }
    BackTracking(0);

    cout << result;

    return 0;
}