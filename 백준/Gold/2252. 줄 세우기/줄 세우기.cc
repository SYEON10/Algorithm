#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<int> sorted;
vector<bool> visited;

void DFS(int i) {
    for (int next : adj_list[i]) {
        if (visited[next]) continue;
        DFS(next);
    }

    sorted.push_back(i);
    visited[i] = true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    adj_list.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    visited[0] = true;

    vector<bool> root(n + 1, true);
    root[0] = false;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        root[to] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (root[i]) {
            DFS(i);
        }
    }

    for (int i = sorted.size() - 1; i >= 0; i--) {
        cout << sorted[i] << ' ';
    }

    return 0;
}