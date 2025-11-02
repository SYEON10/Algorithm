#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

//n = 1e5 => 최대 nlogn
//사실상 a to b 최단거리 = 다익스트라? 
//=> 아... 이거 아닌듯 걍 BFS로 충분...은 아니네 가중치가 있으니까. ..;
//사이클 X 그래프 = 경로는 무조건 하나
//b to a일 수도 있네... 
//아 그냥 DFS 쓸걸...;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<pair<int, int>>> adj_list(n + 1, vector<pair<int, int>>());

    for(int i = 0; i < n-1; i++){
        int from, to, dist;
        cin >> from >> to >> dist;
        adj_list[from].push_back({to, dist});
        adj_list[to].push_back({from, dist});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(n + 1, INT32_MAX);
    vector<int> route(n + 1, 0);
    q.push({0, a});
    dist[a] = 0;
    route[a] = -1;

    int prevDist = INT32_MAX;

    while(!q.empty()){
        int d = q.top().first;
        int node = q.top().second;
        q.pop();

        if(d > dist[node]) continue;

        for(pair<int, int> next : adj_list[node]){
            int nextNode = next.first;
            int nextDist = d + next.second;
            if(nextDist < dist[nextNode]){
                dist[nextNode] = nextDist;
                q.push({nextDist, nextNode});
                route[nextNode] = node;
            }
        }
    }

    int max_dist = 0;
    int prev = b;
    while(route[prev] != -1){
        max_dist = max(max_dist, dist[prev] - dist[route[prev]]);
        prev = route[prev];
    }

    cout << dist[b] - max_dist;

    return 0;
}