#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct direction{
    int r, c;
};

int n;
int max_block;
vector<direction> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int MaxBlock(const vector<vector<int>>& board){
    int ans = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            ans = max(ans, board[r][c]);
        }
    }

    return ans;
}

// now takes merged by reference
void MoveBlock(int r, int c, direction d,
               vector<vector<int>>& board,
               vector<vector<bool>>& merged)
{
    if (board[r][c] == 0) return;

    int new_r = r, new_c = c;
    // slide until just before a non-zero
    while (board[new_r + d.r][new_c + d.c] == 0) {
        new_r += d.r;
        new_c += d.c;
    }

    int tr = new_r + d.r, tc = new_c + d.c;
    // can we merge?
    if (board[tr][tc] == board[r][c] && !merged[tr][tc]) {
        board[tr][tc] *= 2;
        board[r][c] = 0;
        merged[tr][tc] = true;      // ⚡ mark as merged
    }
    // or just move into the empty spot at (new_r,new_c)
    else if (!(new_r == r && new_c == c)) {
        board[new_r][new_c] = board[r][c];
        board[r][c] = 0;
    }
}


vector<vector<int>> Move(direction d, vector<vector<int>> board){
    // track which cells have already merged in *this* move
    vector<vector<bool>> merged(n+2, vector<bool>(n+2, false));

    // scan order unchanged
    if (d.r + d.c < 0) {
        for(int r = 1; r <= n; r++)
            for(int c = 1; c <= n; c++)
                MoveBlock(r, c, d, board, merged);
    }
    else {
        for(int r = n; r >= 1; r--)
            for(int c = n; c >= 1; c--)
                MoveBlock(r, c, d, board, merged);
    }
    return board;
}

void Backtracking(int cnt, vector<vector<int>> board){
    //가지치기 - 5번 이동했으면 끝
    if(cnt <= 0){
        max_block = max(max_block, MaxBlock(board));
        return;
    }
    //모든 경우를 수행하기
    for(direction dir : dirs){
        Backtracking(cnt - 1, Move(dir, board));
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    vector<vector<int>> board(n + 2, vector<int>(n + 2, -1));
    max_block = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            cin >> board[r][c];
        }
    }

    Backtracking(5, board);

    cout << max_block;

    return 0;
}