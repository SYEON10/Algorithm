#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node{
    int w, a, b;
    bool operator<(const node& other) const{
        return w < other.w;
    }
};

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Union(int a, int b, vector<int>& UF){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    if(root_a == root_b) return false;

    if(UF[root_a] < UF[root_b]){
        UF[root_a] += UF[root_b];
        UF[root_b] = root_a;
    }
    else{
        UF[root_b] += UF[root_a];
        UF[root_a] = root_b;
    }
    return true;
}

///루트는 그냥 전부 한 노드로 간주(그래야 사이클 털 때 좋음)
int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<node> nodes(m);
    vector<int> UF(n + 1, -1);

    unordered_map<int, bool> roots;

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        roots[x] = true;
    }

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(roots[u]) u = 0;
        if(roots[v]) v = 0;

        nodes.push_back({w, u, v});
    }

    sort(nodes.begin(), nodes.end());

    int result = 0;

    for(auto& node : nodes){
        if(Union(node.a, node.b, UF)){
            result += node.w;
        }
    }

    cout << result;

    return 0;
}