#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct CCTV {
    int r, c;
    int num;
};

struct Install {
    CCTV tv;
    int dir;
};

vector<vector<int>> matrix;
vector<CCTV> cctv;
vector<int> direction;
int ans = INT32_MAX;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Check(int ct, int dir, vector<vector<int>>& board) {
    int i = 1;
    while (true) {
        int nr = cctv[ct].r + dy[dir] * i;
        int nc = cctv[ct].c + dx[dir] * i;

        if (board[nr][nc] == 6) return;
        if (board[nr][nc] == 0) board[nr][nc] = -1;
        i++;
    }
}

int Calculate() {
    vector<vector<int>> board = matrix;
    for (int i = 0; i < cctv.size(); i++) {
        switch (cctv[i].num) {
        case 1:
            Check(i, direction[i], board);
            break;
        case 2:
            Check(i, direction[i], board);
            Check(i, (direction[i] + 2) % 4, board);
            break;
        case 3:
            Check(i, direction[i], board);
            Check(i, (direction[i] + 1) % 4, board);
            break;
        case 4:
            Check(i, direction[i], board);
            Check(i, (direction[i] + 1) % 4, board);
            Check(i, (direction[i] + 2) % 4, board);
            break;
        case 5:
            Check(i, 0, board);
            Check(i, 1, board);
            Check(i, 2, board);
            Check(i, 3, board);
            break;
        }
    }
    int count = 0;

    for (auto& row : board) {
        for (auto& val : row) {
            if (val == 0) {
                count++;
            }
        }
    }

    return count;
}

//CCTV의 방향에 따라 백트래킹
//cctv 인덱스를 기준으로, 총 4방향으로 돌아감
void BackTracking(int ct) {
    if (ct >= cctv.size()) {
        ans = min(ans, Calculate());
        return;
    }

    for (int i = 0; i < 4; i++) {
        direction[ct] = i;
        BackTracking(ct + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    matrix.assign(n + 2, vector<int>(m + 2, 6));

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            cin >> matrix[r][c];
            if (matrix[r][c] > 0 && matrix[r][c] < 6) {
                cctv.push_back({ r, c, matrix[r][c] });
            }
        }
    }

    direction.resize(cctv.size());

    BackTracking(0);

    cout << ans;

    return 0;
}