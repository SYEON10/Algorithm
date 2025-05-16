#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

void Union(int a, int b, vector<int>& UF, const vector<int>& price){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    if(root_a == root_b) return;

    if(price[root_a] < price[root_b]){
        UF[root_a] += UF[root_b];
        UF[root_b] = root_a;
    }
    else{
        UF[root_b] += UF[root_a];
        UF[root_a] = root_b;
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> price(n + 1, 0);
    vector<int> UF(n + 1, -1);

    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b, UF, price);
    }

    int cost = 0;

    for(int i = 1; i <= n; i++){
        if(UF[i] < 0) cost += price[i];
    }

    if(cost <= k) cout << cost;
    else cout << "Oh no";

    return 0;
}