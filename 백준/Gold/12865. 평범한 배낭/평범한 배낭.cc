//
// Created by syeon on 2023-10-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> products(n + 1, {0, 0});
    vector<int> DP2(k+1);

    for(int i = 1; i <= n; i++){
        cin >> products[i].first >> products[i].second;
    }

    for(int i = 1; i <= n; i++){ //물건 넣기
        for(int j = k; j >= products[i]. first; j--){
            DP2[j] = max(DP2[j], products[i].second + DP2[j - products[i].first]);
        }
    }

    cout << DP2[k];

    return 0;
}
