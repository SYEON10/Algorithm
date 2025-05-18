#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Find(int a, int b, vector<int>& UF){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    //같은 집합일 경우
    if(root_a == root_b) return true;
    return false;
}

void Union(int a, int b, vector<int>& UF){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    //사이클 발견
    if(root_a == root_b) return;

    if(root_a == 0){
        UF[root_a] += UF[root_b];
        UF[root_b] = 0;
        return;
    }
    if(root_b == 0){
        UF[root_b] += UF[root_a];
        UF[root_a] = 0;
        return;
    }

    if(UF[root_a] < UF[root_b]){
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

    int n, m;
    cin >> n >> m;

    //진실을 아는 사람은 루트가 0
    vector<int> UF(n + 1, -1);
    vector<vector<int>> Party(m, vector<int>());

    int c;
    cin >> c;

    for(int i = 0; i < c; i++){
        int x;
        cin >> x;
        UF[x] = 0;
        UF[0]--;
    }

    for(int i = 0; i < m; i++){
        int count, a;
        cin >> count >> a;

        Party[i].push_back(a);

        for(int j = 0; j < count - 1; j++){
            int b;
            cin >> b;
            Party[i].push_back(b);
            Union(a, b, UF);
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        bool checker = true;
        for(int i : Party[i]){
            if(FindRoot(i, UF) == 0){
                checker = false;
                break;
            }
        }
        if(checker) ans++;
    }

    cout << ans;

    return 0;
}