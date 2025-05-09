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

void Union(int a, int b, vector<int>& UF, vector<bool>& cycle){
    int a_root = FindRoot(a, UF);
    int b_root = FindRoot(b, UF);

    if(a_root == b_root) {
        cycle[a_root] = true;
        return;
    }

    if(cycle[a_root] || cycle[b_root]){
        cycle[a_root] = true;
        cycle[b_root] = true;
        return;
    }

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
    int i = 1;

    while(true){

        int v, e;
        cin >> v >> e;

        if(v == 0 && e == 0) break;

        vector<int> UF(v + 1, -1);
        vector<bool> cycle(v + 1, false);

        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;

            Union(a, b, UF, cycle);
        }

        int count = 0;

        for(int i = 1; i <= v; i++){
            if(UF[i] < 0 && !cycle[i]) count++;
        }

        cout << "Case " << i << ": ";

        if(count == 0) cout << "No trees.\n";
        else if(count == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << count << " trees.\n";

        i++;
    }

    return 0;
}