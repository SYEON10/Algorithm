#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int FindRoot(int a, vector<int>& UF){
    if(UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Union(int a, int b, vector<int>& UF){
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    if(root_a == root_b){
        return false;
    }

    if(UF[root_a] < UF[root_b]){
        UF[root_a] += UF[root_b];
        UF[root_b] = root_a;
    }
    else{
        UF[root_b] += UF[root_a];
        UF[root_a] = root_b;
    }

    return true;
}

struct point{
    double x, y;
};

struct node{
    double w;
    int a, b;
    bool operator<(const node& other){
        return w < other.w;
    }
};

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vector<point> matrix(n + 1);
    //weight, matrix의 인덱스
    vector<node> adj;

    for(int i = 1; i <= n; i++){
        cin >> matrix[i].x >> matrix[i].y;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            adj.push_back(node{hypot(matrix[i].x - matrix[j].x, matrix[i].y - matrix[j].y), i, j});
        }
    }

    sort(adj.begin(), adj.end());

    vector<int> UF(n + 1, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        Union(a, b, UF);
    }

    double count = 0;

    for(const auto& n : adj){
        if(Union(n.a, n.b, UF)){
            count += n.w;
        }
    }

    cout << std::fixed << std::setprecision(2);
    cout << count;
    
    return 0;
}