#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<char>> board;

void Recursive(int n, int r, int c){
    if(n == 1){
        board[r][c] = '*';
        return;
    }
    int block = n / 3;
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(i == 1 && j == 1) continue;
            Recursive(block, r + block * i, c + block * j);
        }
    }
}

int main() {
    
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    board.assign(n, vector<char>(n, ' '));

    Recursive(n, 0, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}