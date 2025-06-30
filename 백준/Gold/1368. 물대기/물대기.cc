#include <iostream>
#include <vector>
#include <cmath>
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

    int n;
    int cost = 0;
    cin >> n;
    vector<node> connect_cost;
    vector<int> UF(n + 1, -1);

    int w;

    for(int i = 1; i <= n; i++){
        cin >> w;
        connect_cost.push_back({w, 0, i});
    }

    for(int from = 1; from <= n; from++){
        for(int to = 1; to < from; to++){
            cin >> w;
            connect_cost.push_back({w, from, to});
        }
        for(int to = from; to <= n; to++){
            cin >> w;
        }
    }

    sort(connect_cost.begin(), connect_cost.end());

    for(const auto& n : connect_cost){
        if(Union(n.a, n.b, UF)){
            cost += n.w;
        }
    }

    cout << cost;
    
    return 0;
}