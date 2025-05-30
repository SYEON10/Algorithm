#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int v, e;
    cin >> v >> e;

    vector<int> UF(v + 1, -1);
    multimap<int, pair<int, int>> weight;

    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        
        weight.insert({w, {a, b}});
    }

    int count = 0;

    for(const auto& node : weight){
        if(Union(node.second.first, node.second.second, UF)){
            count += node.first;
        }
    }

    cout << count;
    
    return 0;
}