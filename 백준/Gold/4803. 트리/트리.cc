#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//부모 외 visited 된 node에 방문하게 되면 트리가 아님

struct node{
    int value;
    int parent;
};

bool DFS(const vector<vector<int>>& adj_list, vector<bool>& visited, int v){
    stack<node> dfs;
    dfs.push({v, 0});

    int isTree = true;

    while(!dfs.empty()){
        int node = dfs.top().value;
        int parent = dfs.top().parent;
        dfs.pop();

        visited[node] = true;

        for(int i = 0; i < adj_list[node].size(); i++){
            if(adj_list[node][i] == parent) continue;
            if(visited[adj_list[node][i]]){
                isTree = false;
            }
            else dfs.push({adj_list[node][i], node});
        }
    }

    return isTree;
}

int main()
{
    int case_num = 1;
    while(true){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        vector<vector<int>> adj_list(n + 1);
        vector<bool> visited(n + 1, false);

        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            adj_list[from].emplace_back(to);
            adj_list[to].emplace_back(from);
        }

        int count = 0;
        
        for(int v = 1; v <= n; v++){
            if(visited[v]) continue;
            if(DFS(adj_list, visited, v)) count++;
        }

        cout << "Case " << case_num << ": ";

        switch(count){
            case 0:
                cout << "No trees.\n";
                break;
            case 1:
                cout << "There is one tree.\n";
                break;
            default:
                cout << "A forest of " << count << " trees.\n";
                break;
        }

        case_num++;
    }

    return 0;
}