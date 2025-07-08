#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

//각 건물 완성의 최소 시간 -> 부모 수가 0이 되었을 때의 Max 부모의 완성 시간!
//각 부모의 최소 시간을 DP로 기록해두기

int main() {
    
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> adj_list(n + 1, vector<int>());
    vector<int> time(n + 1);
    vector<int> parents(n + 1, 0);
    vector<int> DP(n + 1, 0);
    queue<int> q;

    for(int i = 1; i <= n; i++){
        int t, parent;
        cin >> t;
        time[i] = t;
        while(cin >> parent){
            if(parent == -1) break;
            adj_list[parent].push_back(i);
            parents[i]++;
        }
        if(parents[i] == 0) {
            q.push(i);
            DP[i] = t;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto next : adj_list[node]){
            parents[next]--;
            DP[next] = max(DP[next], DP[node]);
            if(parents[next] == 0){
                q.push(next);
                DP[next] += time[next];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << DP[i] << '\n';
    }

    return 0;
}