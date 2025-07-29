#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> cost;
vector<vector<int>> adj_list;
vector<vector<int>> DP; // node가 우수마을일 때/아닐 때 최대 주민 수

int DFS(int node, int prev, int good) {
    if (DP[node][good] != -1) 
        return DP[node][good];

    if (good) {
        DP[node][good] = cost[node];
        for (int next : adj_list[node]) {
            if (next == prev) continue;
            if (good) DP[node][good] += DFS(next, node, 0);
        }
    }
    else {
        bool hasGood = false;
        int goodValue = 0;
        DP[node][good] = 0;
        for (int next : adj_list[node]) {
            if (next == prev) continue;
            int nextgood = DFS(next, node, 1);
            int nextbad = DFS(next, node, 0);

            if (nextgood >= nextbad) {
                DP[node][good] += nextgood;
                hasGood = true;
            }
            else {
                DP[node][good] += nextbad;
                goodValue = min(goodValue, nextbad - nextgood);
            }
        }
        if (!hasGood) DP[node][good] -= goodValue;
    }

    return DP[node][good];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cost.assign(n + 1, 0);
    DP.assign(n + 1, vector<int>(2, -1));
    adj_list.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    cout << max(DFS(1, 0, 1), DFS(1, 0, 0));

    return 0;
}