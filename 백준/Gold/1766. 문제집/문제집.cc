#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1, vector<int>());
    vector<int> parents(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        parents[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(parents[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        cout << node << ' ';

        for(auto next : adj_list[node]){
            parents[next]--;
            if(parents[next] == 0){
                pq.push(next);
            }
        }
    }

    return 0;
}