#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 1e6;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

void Union(int a, int b, vector<int>& UF){
    int a_root = FindRoot(a, UF);
    int b_root = FindRoot(b, UF);

    if(a_root == b_root) {
        cout << abs(UF[a_root]) << '\n';
        return;
    }

    if(abs(UF[a_root]) > abs(UF[b_root])){
        UF[a_root] += UF[b_root];
        UF[b_root] = a_root;
        cout << abs(UF[a_root]) << '\n';
    }
    else{
        UF[b_root] += UF[a_root];
        UF[a_root] = b_root;
        cout << abs(UF[b_root]) << '\n';
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> UF(1e6, -1);
        unordered_map<string, int> Friend;
        int count = 0;

        while(n--){
            string a, b;
            cin >> a >> b;

            if(Friend[a] == 0) {
                Friend[a] = ++count;
            }
            if(Friend[b] == 0) {
                Friend[b] = ++count;
            }

            Union(Friend[a], Friend[b], UF);
        }
    }

    return 0;
}