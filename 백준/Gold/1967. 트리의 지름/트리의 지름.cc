#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<pair<int, int>>> adj_map;
vector<int> DP;

//node의 자식 값의 Max
int DFS(int node){

    if(DP[node]){
        return DP[node];
    }

    int max_value = 0;
    for(pair<int, int> next : adj_map[node]){
        max_value = max(max_value, DFS(next.first) + next.second);
    }

    return DP[node] = max_value;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    DP.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++){
        int node, parent, weight;
        cin >> parent >> node >> weight;

        adj_map[parent].push_back({node, weight});
    }

    int ans = 0;

    for(int node = 1; node <= n; node++){

        vector<int> temp(2, 0);
        for(pair<int, int> next : adj_map[node]){
            temp.push_back(DFS(next.first) + next.second);
        }

        sort(temp.begin(), temp.end(), greater<int>());

        ans = max(ans, temp[0] + temp[1]);
    }

    cout << ans;

    return 0;
}