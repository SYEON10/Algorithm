#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj_list;
vector<vector<int>> DP; //node가 얼리/언얼리일 때 최소 언얼리 수

//root를 넣어 시작
int DFS(int node, int prev, int early) {
    if (DP[node][early] != -1) return DP[node][early];

    if (early == 1) DP[node][1] = 1;
    else DP[node][0] = 0;
    for (int child : adj_list[node]) {
        if (prev == child) continue;
        if (early == 1) DP[node][1] += min(DFS(child, node, 1), DFS(child, node, 0));
        else DP[node][0] += DFS(child, node, 1);
    }

    return DP[node][early];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    adj_list.assign(n + 1, vector<int>());
    DP.assign(n + 1, vector<int>(2, -1));

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    cout << min(DFS(1, 0, 1), DFS(1, 0, 0));

    return 0;
}