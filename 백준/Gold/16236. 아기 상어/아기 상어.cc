#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int initLevel = 2;

struct point {
    int r;
    int c;
    int time;

    // priority_queue에서 사용할 비교 연산자
    bool operator<(const point& other) const {
        if (time != other.time) return time > other.time;  // 거리 우선 (작은 time 우선)
        if (r != other.r) return r > other.r;              // 위쪽 우선 (작은 r 우선)
        return c > other.c;                                // 왼쪽 우선 (작은 c 우선)
    }
};

vector<point> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

point FindNextFish(const point& startPos, int level, const vector<vector<int>>& matrix) {
    int n = matrix.size() - 1;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<point> q;
    priority_queue<point> fishCandidates;

    q.push(startPos);
    visited[startPos.r][startPos.c] = true;

    while (!q.empty()) {
        point node = q.front(); q.pop();

        for (const point& dir : directions) {
            int nr = node.r + dir.r;
            int nc = node.c + dir.c;

            if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
            if (visited[nr][nc]) continue;
            if (matrix[nr][nc] > level) continue;  // 지나갈 수 없는 큰 물고기

            visited[nr][nc] = true;
            point next = { nr, nc, node.time + 1 };

            if (matrix[nr][nc] != 0 && matrix[nr][nc] < level) {
                fishCandidates.push(next);  // 먹을 수 있는 물고기 후보 저장
            }

            q.push(next);  // 계속 탐색
        }
    }

    if (fishCandidates.empty()) return { 0, 0, -1 };
    return fishCandidates.top();  // 우선순위 가장 높은 물고기 리턴
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int currentLevel = initLevel;
    int exp = 0;
    point pos;

    // 1-based 인덱스 사용
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));

    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            cin >> matrix[r][c];
            if (matrix[r][c] == 9) {
                pos = { r, c, 0 };
                matrix[r][c] = 0;  // 아기 상어가 있던 자리는 빈칸으로
            }
        }
    }

    int timer = 0;
    while (true) {
        point nextFish = FindNextFish(pos, currentLevel, matrix);
        if (nextFish.time == -1) break;

        // 물고기 먹기
        pos = { nextFish.r, nextFish.c, 0 };
        timer += nextFish.time;
        matrix[pos.r][pos.c] = 0;
        exp++;

        // 성장 조건
        if (exp == currentLevel) {
            currentLevel++;
            exp = 0;
        }
    }

    cout << timer << '\n';
    return 0;
}
