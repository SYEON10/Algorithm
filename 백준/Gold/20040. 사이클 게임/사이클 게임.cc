#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Union(int a, int b, vector<int>& UF){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    //사이클 발견
    if(root_a == root_b) return true;

    if(UF[root_a] < UF[root_b]){
        UF[root_a] += UF[root_b];
        UF[root_b] = root_a;
    }
    else{
        UF[root_b] += UF[root_a];
        UF[root_a] = root_b;
    }

    return false;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> UF(n, -1);

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;

        if(Union(a, b, UF)){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}