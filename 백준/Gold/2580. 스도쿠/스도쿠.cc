#include <iostream>
#include <vector>

using namespace std;

int SIZE = 9;
vector<vector<int>> board;
vector<vector<bool>> checkerHorizon;
vector<vector<bool>> checkerVertical;
vector<vector<bool>> checkerSquare;

bool Calculate(int index) {
    if (index == SIZE * SIZE) {
        return true;
    }

    int r = index / SIZE;
    int c = index % SIZE;

    if (board[r][c] != 0)
        return Calculate(index + 1);

    for (int i = 1; i <= SIZE; i++) {
        if (!checkerSquare[(r / 3) * 3 + (c / 3)][i] && !checkerHorizon[r][i] && !checkerVertical[c][i]) {

            checkerSquare[(r / 3) * 3 + (c / 3)][i] = true;
            checkerHorizon[r][i] = true;
            checkerVertical[c][i] = true;

            board[r][c] = i;
            if (Calculate(index + 1)) {
                return true;
            }
            board[r][c] = 0;

            checkerSquare[(r / 3) * 3 + (c / 3)][i] = false;
            checkerHorizon[r][i] = false;
            checkerVertical[c][i] = false;
        }
    }

    return false;
}

int main() {

    board.assign(SIZE, vector<int>(SIZE));
    checkerHorizon.assign(SIZE, vector<bool>(SIZE + 1));
    checkerVertical.assign(SIZE, vector<bool>(SIZE + 1));
    checkerSquare.assign(SIZE, vector<bool>(SIZE + 1));

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            cin >> board[r][c];
            if (board[r][c] != 0) {
                checkerHorizon[r][board[r][c]] = true;
                checkerVertical[c][board[r][c]] = true;
                checkerSquare[(r / 3) * 3 + (c / 3)][board[r][c]] = true;
            }
        }
    }

    Calculate(0);

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
