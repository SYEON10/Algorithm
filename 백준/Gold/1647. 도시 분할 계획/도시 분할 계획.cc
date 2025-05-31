#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000;

int FindRoot(int a, vector<int>& UF) {
    if (UF[a] < 0) return a;
    return UF[a] = FindRoot(UF[a], UF);
}

bool Union(int a, int b, vector<int>& UF) {
    int root_a = FindRoot(a, UF);
    int root_b = FindRoot(b, UF);

    if (root_a == root_b) {
        return false;
    }

    if (UF[root_a] < UF[root_b]) {
        UF[root_a] += UF[root_b];
        UF[root_b] = root_a;
    }
    else {
        UF[root_b] += UF[root_a];
        UF[root_a] = root_b;
    }

    return true;
}

struct node {
    int w, a, b;
    bool operator<(const node& other) const {
        return w < other.w;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    //다 최소로 연결하고
    //그 중 제일 비싼 하나를 끊어버리기

    int n, m;
    cin >> n >> m;

    vector<node> route(m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        route[i] = { w, a, b };
    }

    sort(route.begin(), route.end());

    vector<int> UF(n + 1, -1);

    int sum = 0;
    int max_value = 0;
    for (const node& n : route) {
        if (Union(n.a, n.b, UF)) {
            sum += n.w;
            max_value = max(max_value, n.w);
        }
    }

    sum -= max_value;

    cout << sum;
    return 0;
}