#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

//9시 15분까지
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> costs(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> costs[i];
        }

        vector<vector<int>> adj_list(n + 1, vector<int>());
        vector<int> parents(n + 1, 0);
        vector<int> time_checker(n + 1, 0);

        for(int i = 0; i < k; i++){
            int from, to;
            cin >> from >> to;
            adj_list[from].push_back(to);
            parents[to]++;
        }

        int target;
        cin >> target;

        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(parents[i] == 0) {
                time_checker[i] = costs[i];
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node = q.front(); q.pop();
            int num = node;
            int timer = time_checker[num];

            for(int next : adj_list[num]){
                parents[next]--;

                time_checker[next] = max(time_checker[next], timer + costs[next]);

                if(parents[next] == 0){
                    q.push(next);
                }
            }
        }

        cout << time_checker[target] << '\n';
    }

    return 0;
}