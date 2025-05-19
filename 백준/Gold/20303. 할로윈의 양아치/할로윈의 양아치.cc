#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

void Union(int a, int b, vector<int>& UF){
    int a_root = FindRoot(a, UF);
    int b_root = FindRoot(b, UF);

    if(a_root == b_root) return;

    if(abs(UF[a_root]) > abs(UF[b_root])){
        UF[a_root] += UF[b_root];
        UF[b_root] = a_root;
    }
    else{
        UF[b_root] += UF[a_root];
        UF[a_root] = b_root;
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    k--;

    vector<int> UF(n + 1, -1);
    vector<int> Candy(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> Candy[i];
    }

    while(m--){
        int a, b;
        cin >> a >> b;

        Union(a, b, UF);
    }

    //아이들 수/캔디 수
    vector<pair<int, int>> knapsak;

    for(int i = 1; i <= n; i++){
        int root_i = FindRoot(i, UF);
        if(root_i != i){
            Candy[root_i] += Candy[i];
            Candy[i] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        if(Candy[i] > 0){
            knapsak.push_back({-UF[i], Candy[i]});
        }
    }

    //index : 무게, value : 최대 캔디 수
    vector<int> DP(k + 1, 0);

    for(int i = 0; i < knapsak.size(); i++){
        for(int j = k - knapsak[i].first; j >= 0; j--){
            DP[j + knapsak[i].first] = max(DP[j + knapsak[i].first], DP[j] + knapsak[i].second);
        }
    }

    cout << DP[k];

    return 0;
}