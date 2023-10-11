#include <iostream>
#include <vector>

using namespace std;

//최대 N * M -> 50 * 50 = 250
//연산 수 -> 64
//총 연산 수 250 * 64 -> 브루트포스

//보드, 좌표 전달 시 개수 반환하는 함수
//순회

int CountRecolor(const vector<vector<char>> &board, const int row, const int col, const char first){
    int count = 0;

    //row + col이 짝수면 첫번째 타일, 홀수면 두번째 타일. 아닐 시 count++.
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0 && board[i + row][j + col] != first){ //짝수고 첫번째 타일이 아니면 count
                count++;
                continue;
            }
            if((i + j) % 2 != 0 && board[i + row][j + col] == first){ //홀수고 두번째 타일이 아니면 count
                count++;
                continue;
            }
        }
    }

    return count;
}

int main(){

    int row, col, recolor, result = 64;
    cin >> row >> col;
    vector<vector<char>> board(row);
    vector<char> line(col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> line[j];
        }
        board[i] = line;
    }

    for(int i = 0; i <= row - 8; i++){
        for(int j = 0; j <= col - 8; j++){
            recolor = min(CountRecolor(board, i, j, 'W'), CountRecolor(board, i, j, 'B'));
            result = min(recolor, result);
        }
    }

    cout << result;

    return 0;
}