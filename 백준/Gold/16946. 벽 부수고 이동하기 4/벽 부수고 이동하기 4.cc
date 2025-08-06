#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int SIZE = 1001;

int n, m;
int code = 1;
vector<vector<int>> board;
vector<vector<pair<int, int>>> DP;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

//붙어있는 0의 개수를 세기
int DFS1(int r, int c) {
    int count = 1;
    board[r][c] = -1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (board[nr][nc] == 1 || board[nr][nc] == -1) continue;
        count += DFS1(nr, nc);
    }
    return count;
}

//붙어있는 0을 count로 바꾸기
void DFS2(int r, int c, int count) {
    DP[r][c] = { count, code };

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (board[nr][nc] != -1 || DP[nr][nc].first != 0) continue;
        DFS2(nr, nc, count);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    board.assign(n + 2, vector<int>(m + 2, 1));
    DP.assign(n + 2, vector<pair<int, int>>(m + 2, { 0, -1 }));

    string input;
    for (int r = 1; r <= n; r++) {
        cin >> input;
        for (int c = 0; c < m; c++) {
            board[r][c + 1] = input[c] - '0';
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (board[r][c] != 0) continue;
            int count = DFS1(r, c);
            DFS2(r, c, count);
            code++;
        }
    }

    set<int> code;

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            int count = 1;
            if (board[r][c] == 1) {
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    auto it = code.find(DP[nr][nc].second);
                    if (it != code.end()) {
                        continue;
                    }
                    code.insert(DP[nr][nc].second);
                    count += DP[nr][nc].first;
                }
            }
            else count = 0;
            cout << count % 10;
            code.clear();
        }
        cout << '\n';
    }

    return 0;
}