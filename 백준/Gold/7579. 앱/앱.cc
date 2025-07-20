#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> apps(n);
    int sum_cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> apps[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> apps[i].second;
        sum_cost += apps[i].second;
    }

    //m바이트 이상을 남기는 최소 c
    //중복 X
    //c가 인덱스
    vector<int> DP(sum_cost + 1, 0);

    for (auto& app : apps) {
        int mem = app.first;
        int cost = app.second;
        for (int c = sum_cost; c >= cost; c--) {
            DP[c] = max(DP[c], DP[c - cost] + mem);
        }
    }

    for (int c = 0; c <= sum_cost; c++) {
        if (DP[c] >= m) {
            cout << c;
            break;
        }
    }

    return 0;
}