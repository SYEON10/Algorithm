#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<map<int, int>> DP;

//before -> node의 값
int DFS(int node, int before){
    if(DP[before][node]){
        return DP[before][node];
    }

    int max_value = 0;

    for(int i = 0; i < adj_list[node].size(); i++){
        if(before == adj_list[node][i]){
            continue;
        }
        max_value = max(max_value, DFS(adj_list[node][i], node));
    }

    return DP[before][node] = max_value + 1;
}


int main()
{
    int n;
    cin >> n;

    adj_list.assign(n + 1, vector<int>());
    DP.assign(n + 1, map<int, int>());

    for(int i = 0; i < n - 1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(adj_list[i].size() < 3) continue;

        vector<int> sorted;
        for(int node : adj_list[i]){
            sorted.push_back(DFS(node, i));
        }

        sort(sorted.begin(), sorted.end(), std::greater<int>());

        ans = max(ans, sorted[0] + sorted[1] + sorted[2] + 1);
    }

    cout << ans;

    return 0;
}