#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindRoot(int a, const vector<int>& UF){
    int a_root = a;

    while(UF[a_root] > -1){
        a_root = UF[a_root];
    }

    return a_root;
}

string Find(int a, int b, const vector<int>& UF){
    int a_root = FindRoot(a, UF);
    int b_root = FindRoot(b, UF);

    if(a_root == b_root) return "YES";
    return "NO";
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

    int n, m;
    cin >> n >> m;

    vector<int> UF(n + 1, -1);

    for(int i = 0; i < m; i++){
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if(cmd == 1){
            cout << Find(a, b, UF) << '\n';
        }
        if(cmd == 0){
            Union(a, b, UF);
        }
    }

    return 0;
}