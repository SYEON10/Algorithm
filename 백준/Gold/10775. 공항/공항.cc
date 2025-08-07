#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int SIZE = 1e5 + 1;

int parent[SIZE];

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int g, p;
    cin >> g >> p;

    for(int i = 0; i <= g; i++){
        parent[i] = i;
    }

    int count = 0;

    for(int i = 0; i < p; i++){
        int gi;
        cin >> gi;

        int dock = Find(gi);

        if(dock == 0) break;

        count++;
        parent[dock] = Find(dock - 1);
    }

    cout << count;

    return 0;
}