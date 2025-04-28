#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> cnt;

int DFS(int node, int parent){
    for(int i = 0; i < tree[node].size(); i++){
        if(tree[node][i] == parent) continue;
        cnt[node] += DFS(tree[node][i], node);
    }

    return cnt[node] += 1;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, r, q;
    cin >> n >> r >> q;

    tree.assign(n + 1, vector<int>());
    cnt.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++){
        int node1, node2;
        cin >> node1 >> node2;

        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    DFS(r, 0);    

    for(int i = 0; i < q; i++){
        int query = 0;
        cin >> query;

        cout << cnt[query]<< '\n';
    }

    return 0;
}