#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Union(const int a, const int b, vector<int>& UF){
    int ra = FindRoot(a, UF);
    int rb = FindRoot(b, UF);

    if(ra == rb){
        return false;
    }

    if(UF[ra] < UF[rb]){
        UF[ra] += UF[rb];
        UF[rb] = ra;
    }
    else{
        UF[rb] += UF[ra];
        UF[ra] = rb;
    }
    return true;
}

struct node{
    int w, a, b;
    bool operator<(const node& other) const{
        return w < other.w;
    }
};

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int v, e;
    cin >> v >> e;

    vector<int> UF(v + 1, -1);
    vector<node> weight;

    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        
        weight.push_back({w, a, b});
    }

    sort(weight.begin(), weight.end());

    int count = 0;
    int required = 0;

    for(const auto& node : weight){
        if(Union(node.a, node.b, UF)){
            count += node.w;
            if(++required == v - 1) break;
        }
    }

    cout << count;
    
    return 0;
}