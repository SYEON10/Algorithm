#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, d, max_kill = 0;
vector<vector<int>> board;
vector<pair<int, int>> dir = { {0, -1}, {-1, 0}, {0, 1} };

pair<int, int> BFS(const vector<vector<int>>& turn, const pair<int, int>& root) {

    if (turn[root.first][root.second] == 1) {
        return root;
    }

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    q.push({root.first, root.second, 1 });
    visit[root.first][root.second] = true;

    while (!q.empty()) {
        auto [r, c, dist] = q.front(); q.pop();
        
        if(dist >= d) continue;

        for (int i = 0; i < dir.size(); i++) {
            int new_r = r + dir[i].first;
            int new_c = c + dir[i].second;

            if (new_r < 0 || new_c < 0 || new_c >= m) 
                continue;

            if (visit[new_r][new_c]) continue;

            visit[new_r][new_c] = true;

            if (turn[new_r][new_c] == 1) {
                return { new_r, new_c };
            }

            q.push({ new_r, new_c, dist + 1 });
        }
    }

    return { -1, -1 };
}

int Simulation(const vector<int>& archers) {
    vector<vector<int>> turn = board;
    vector<int> archer_pos;
    int kill_count = 0;

    for (int i = 0; i < m; i++) {
        if (archers[i] == 1) {
            archer_pos.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) { //총 n번 반복 -> 이 경우 무조건 끝이 남
        set<pair<int, int>> target;
        for (int a = 0; a < 3; a++) {
            pair<int, int> pos = BFS(turn, { n - 1, archer_pos[a] });
            if (pos.first == -1) continue;
            target.insert(pos);
        }
        kill_count += target.size();
        for (auto& t : target) {
            turn[t.first][t.second] = 0;
        }

        bool empty = true;
        vector<vector<int>> next(n + 1, vector<int>(m, 0));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (turn[r][c] == 1) {
                    next[r + 1][c] = 1;
                    empty = false;
                }
            }
        }
        turn = next;
        if (empty) break;
    }

    return kill_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> d;

    board.assign(n + 1, vector<int>(m, 0));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> board[r][c];
        }
    }

    vector<int> archers(m, 0);
    archers[m - 1] = 1, archers[m - 2] = 1, archers[m - 3] = 1;

    do {
        max_kill = max(max_kill, Simulation(archers));
    } while (next_permutation(archers.begin(), archers.end()));

    cout << max_kill;

    return 0;
}