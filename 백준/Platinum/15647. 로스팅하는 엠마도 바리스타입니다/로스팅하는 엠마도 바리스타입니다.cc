#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<vector<pair<int, int>>> tree; //다음 노드/비용
vector<pair<long long, long long>> DP; //prev node 노드 수/노드 값의 합
vector<long long> ans;

pair<long long, long long> CreateDP(int node, int prev) {
    if (DP[node].first != -1) {
        return DP[node];
    }

    long long nodecount = 0;
    long long nodecost = 0;
    for (auto next : tree[node]) {
        if (next.first == prev) continue;
        pair<long long, long long> nextpair = CreateDP(next.first, node);
        nodecount += nextpair.first + 1;
        nodecost += (nextpair.first + 1) * (long long)next.second + (long long)nextpair.second;
    }

    return DP[node] = { nodecount, nodecost };
}

void DFS(int node, int prev, long long cost) {
    long long nodecount = DP[node].first + 1;
    long long nodecost = DP[node].second;

    long long prevNodeCount = n;
    prevNodeCount -= nodecount;
    long long prevNodeCost = ans[prev];
    prevNodeCost -= nodecost + nodecount * cost;

    nodecost += prevNodeCost + prevNodeCount * cost;
    ans[node] = nodecost;

    for (auto next : tree[node]) {
        if (next.first == prev) continue;
        DFS(next.first, node, next.second);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    tree.assign(n + 1, vector<pair<int, int>>());
    DP.assign(n + 1, { -1, -1 });
    ans.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        tree[x].push_back({ y, cost });
        tree[y].push_back({ x, cost });
    }

    ans[1] = CreateDP(1, 0).second;

    for (auto next : tree[1]) {
        DFS(next.first, 1, next.second);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}