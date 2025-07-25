#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_COST = 1e5;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> DP(n + 1, vector<int>(n + 1, MAX_COST));
    vector<vector<int>> track(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        DP[from][to] = min(DP[from][to], cost); //중복 경로가 있으면 min 처리 필요
        track[from][to] = to;
    }

    for (int i = 1; i <= n; i++) {
        DP[i][i] = 0;
    }

    //DP[from][to] = from에서 to까지 가는 최단경로
    //track[from][to] = from부터 to까지 가는 길에서 from 바로 다음에 와야 할 노드

    for (int k = 1; k <= n; k++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (DP[from][k] == MAX_COST || DP[k][to] == MAX_COST) continue;
                if (DP[from][to] > DP[from][k] + DP[k][to]) {
                    DP[from][to] = DP[from][k] + DP[k][to];
                    track[from][to] = track[from][k];
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
            if (i == j || track[i][j] == 0) {
                cout << 0 << '\n';
                continue;
            }

            vector<int> path;
            path.push_back(i);

            for(int from = i; from != j; from = track[from][j]){
                path.push_back(track[from][j]);
            }

            cout << path.size() << ' ';
            for(auto p : path){
                cout << p << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}