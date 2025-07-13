#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int CheckLine(int n, int l, const vector<vector<int>>& board){
    int count = 0;
    for(int r = 0; r < n; r++){
        int seq = 1;
        int pos = true;
        for(int c = 1; c < n; c++){
            if(board[r][c] == board[r][c - 1]){
                seq++;
                continue;
            }
            if(board[r][c] == 1 + board[r][c - 1] && seq >= l){
                seq = 1;
                continue;
            }
            if(board[r][c] == -1 + board[r][c - 1]){
                seq = 1;
                for(int i = 1; i < l; i++){
                    if(c + i < n && board[r][c + i] == board[r][c]){
                        seq++;
                        continue;
                    }
                    break;
                }
                if(seq >= l){
                    c += l - 1;
                    seq = 0;
                }
                else {
                    pos = false;
                    break;
                }
                continue;
            }

            pos = false;
            break;
        }
        if(pos) {
            count++;
        }
    }

    for(int c = 0; c < n; c++){
        int seq = 1;
        int pos = true;
        for(int r = 1; r < n; r++){
            if(board[r][c] == board[r - 1][c]){
                seq++;
                continue;
            }
            if(board[r][c] == 1 + board[r - 1][c] && seq >= l){
                seq = 1;
                continue;
            }
            if(board[r][c] == -1 + board[r - 1][c]){
                seq = 1;
                for(int i = 1; i < l; i++){
                    if(r + i < n && board[r + i][c] == board[r][c]){
                        seq++;
                        continue;
                    }
                    break;
                }
                if(seq >= l){
                    r += l - 1;
                    seq = 0;
                }
                else {
                    pos = false;
                    break;
                }
                continue;
            }

            pos = false;
            break;
        }
        if(pos) {
            count++;
        }
    }

    return count;
}

//브루트포스
//쭉 돌면서 조건을 만족하면 놓고, 만약 한 줄이 어차피 안 된다면 놓은 경사로를 전부 파괴함
//만약 하나의 경사로를 놓아 두 개의 경사로를 놓을 길을 막는다면? -> 코너케이스
int main() {
    
    cin.tie(0) -> sync_with_stdio(0);

    int n, l;
    cin >> n >> l;

    vector<vector<int>> board(n, vector<int>(n));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> board[r][c];
        }
    }

    cout << CheckLine(n, l, board);

    return 0;
}