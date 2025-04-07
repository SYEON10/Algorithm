#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e8 + 1;

//다익스트라

void Dijkstra(const vector<vector<pair<int, int>>>& adj_list, int c){
    int n = adj_list.size();

    priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INF);

    distance[c] = 0;
    pq.push({0, c});

    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(time > distance[node]) continue;

        for(auto nextnode : adj_list[node]){
            if(distance[nextnode.first] > time + nextnode.second){
                distance[nextnode.first] = time + nextnode.second;
                pq.push({distance[nextnode.first], nextnode.first});
            }
        }
    }

    int time = 0;
    int count = 0;
    for(int i = 1; i < n; i++){
        if(distance[i] == INF) continue;
        count++;
        time = max(time, distance[i]);
    }

    cout << count << ' ' << time << '\n';
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int, int>>> adj_list(n + 1);
        for(int i = 0; i < d; i++){
            int a, b, s;
            cin >> a >> b >> s;

            adj_list[b].push_back({a, s});
        }
        Dijkstra(adj_list, c);
    }
    return 0;
}