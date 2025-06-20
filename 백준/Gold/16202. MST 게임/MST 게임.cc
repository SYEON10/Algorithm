#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    int a, b, w;
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

int Kruscal(const int n, const vector<node>& edge){
    int sum = 0;
    int count = 0;
    vector<int> UF(n + 1, -1);

    for(auto& e : edge){
        if(Union(e.a, e.b, UF)){
            sum += e.w;
            count++;
        }
    }

    if(count != n - 1) return 0;

    return sum;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<node> edge(m);

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        edge[i - 1] = {a, b, i};
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < k; i++){
        cout << Kruscal(n, edge) << ' ';
        edge.erase(edge.begin());
    }
    
    return 0;
}