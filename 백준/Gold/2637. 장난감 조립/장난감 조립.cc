#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj_list(n + 1, vector<pair<int, int>>(n + 1));
    vector<bool> basic(n + 1, true);
    vector<int> parents(n + 1, 0);
    vector<int> cost(n + 1, 0);
    cost[n] = 1;

    for(int i = 0; i < m; i++){
        int to, from, count;
        cin >> to >> from >> count;

        basic[to] = false;
        parents[from]++;
        adj_list[to].push_back({from, count});
    }

    queue<int> bfs;
    bfs.push(n);

    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        //cout << node << '\n';

        for(const auto next : adj_list[node]){
            parents[next.first]--;
            cost[next.first] += next.second * cost[node];
            if(parents[next.first] == 0){
                bfs.push(next.first);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(basic[i]) cout << i << ' ' << cost[i] << '\n';
    }
    
    return 0;
}