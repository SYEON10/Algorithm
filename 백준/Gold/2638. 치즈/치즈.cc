#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct point {
    int r, c;
};

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

// 외부 공기 탐색
void BFS(point start, const vector<vector<int>>& board, vector<vector<bool>>& outer) {
    queue<point> bfs;
    bfs.push(start);
    outer[start.r][start.c] = true;

    while (!bfs.empty()) {
        point p = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) continue;
            if (board[nr][nc] == 1 || outer[nr][nc]) continue;

            outer[nr][nc] = true;
            bfs.push({nr, nc});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> outer(n + 2, vector<bool>(m + 2, false));
    int cheeseCount = 0;
    int time = 0;

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            cin >> matrix[r][c];
            if (matrix[r][c] == 1) cheeseCount++;
        }
    }

    // 외부 공기 초기화
    BFS({0, 0}, matrix, outer);

    while (cheeseCount > 0) {
        vector<point> toMelt;

        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                if (matrix[r][c] != 1) continue;

                int airCount = 0;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (outer[nr][nc]) airCount++;
                }

                if (airCount >= 2) {
                    toMelt.push_back({r, c});
                }
            }
        }

        // 치즈 녹이기
        for (auto& node : toMelt) {
            matrix[node.r][node.c] = 0;
        }

        cheeseCount -= toMelt.size();
        time++;

        // 외부 공기 갱신
        outer = vector<vector<bool>>(n + 2, vector<bool>(m + 2, false));
        BFS({0, 0}, matrix, outer);
    }

    cout << time << '\n';
    return 0;
}
