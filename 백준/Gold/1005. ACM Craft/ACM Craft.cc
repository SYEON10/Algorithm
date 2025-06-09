#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TopologySort(int n, int w, const vector<int>& cost, vector<int>& parents, const vector<vector<int>>& adj_list){

    vector<bool> visited(n + 1, false);
    vector<int> DP(n + 1, 0);

    int count = 0;

    visited[0] = true;

    for(int p = 1; p <= n; p++){
        if(parents[p] == 0) {
            DP[p] = cost[p];
        }
    }

    while(count < n){
        for(int p = 1; p <= n; p++){
            if(parents[p] > 0) continue;
            if(visited[p]) continue;
            visited[p] = true;
            count++;
            if(p == w) return DP[w];
            for(int i : adj_list[p]){
                parents[i]--;
                DP[i] = max(DP[i], DP[p] + cost[i]);
            }
        }
    }

    return DP[w];
}

int main() {

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n, k, w;
        cin >> n >> k;

        vector<int> cost(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> cost[i];
        }

        vector<int> parents(n + 1, 0);
        vector<vector<int>> adj_list(n + 1, vector<int>());

        for(int i = 0; i < k; i++){
            int from, to;
            cin >> from >> to;

            adj_list[from].push_back(to);
            parents[to]++;
        }

        cin >> w;

        cout << TopologySort(n, w, cost, parents, adj_list) << '\n';
    }

    return 0;
}