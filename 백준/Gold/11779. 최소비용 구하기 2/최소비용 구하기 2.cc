#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj_list(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<int> track(n + 1, -1);

    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        adj_list[from].push_back({to, cost});
    }

    int start, end;
    cin >> start >> end;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost > dist[node]) continue;

        for(auto next : adj_list[node]){
            int nextcost = next.second;
            int nextnode = next.first;
            if(dist[node] + nextcost >= dist[nextnode]) continue;
            dist[nextnode] = dist[node] + nextcost;
            pq.push({dist[nextnode], nextnode});
            track[nextnode] = node;
        }
    }

    cout << dist[end] << '\n';

    vector<int> path;

    for(int before = end; before != -1; before = track[before]){
        path.push_back(before);
    }

    cout << path.size() << '\n';
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << ' ';
    }

    return 0;
}