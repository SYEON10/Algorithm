#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    vector<vector<pair<int, int>>> adj_list(v + 1);
    vector<int> distance(v + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1; i <= e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist > distance[node]) continue;

        for(auto next : adj_list[node]){
            int weight = next.second;
            int nextnode = next.first;
            if(distance[node] + weight < distance[nextnode]){
                distance[nextnode] = distance[node] + weight;
                pq.push({distance[nextnode], nextnode});
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(distance[i] == INT32_MAX) cout << "INF\n";
        else cout << distance[i] << '\n';
    }

    return 0;
}