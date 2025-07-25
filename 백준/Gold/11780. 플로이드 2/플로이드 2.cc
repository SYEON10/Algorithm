#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_COST = 1e5;

vector<vector<int>> DP;
vector<vector<int>> track;
vector<int> ans;

void BackTrack(int from, int to) {
    if (track[from][to] == -1) {
        return;
    }
    if (track[from][to] == 0) {
        ans.push_back(from);
        return;
    }

    BackTrack(from, track[from][to]);
    BackTrack(track[from][to], to);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    DP.assign(n + 1, vector<int>(n + 1, MAX_COST));
    track.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        DP[from][to] = min(DP[from][to], cost); //중복 경로가 있으면 min 처리 필요
        track[from][to] = 0;
    }

    for (int i = 1; i <= n; i++) {
        DP[i][i] = 0;
        track[i][i] = 0;
    }

    //DP[from][to] = from에서 to까지 가는 최단경로

    for (int k = 1; k <= n; k++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (DP[from][k] == MAX_COST || DP[k][to] == MAX_COST) continue;
                if (DP[from][to] > DP[from][k] + DP[k][to]) {
                    DP[from][to] = DP[from][k] + DP[k][to];
                    track[from][to] = k;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (DP[i][j] == MAX_COST) cout << 0 << ' ';
            else cout << DP[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << 0 << '\n';
                continue;
            }
            BackTrack(i, j);
            if (ans.size() == 0) {
                cout << 0 << '\n';
                continue;
            }
            cout << ans.size() + 1 << ' ';
            for (auto k : ans) {
                cout << k << ' ';
            }
            cout << j << '\n';
            ans.clear();
        }
    }
    return 0;
}