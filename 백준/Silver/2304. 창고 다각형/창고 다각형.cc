#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//오목하면 안 됨

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> bars;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        bars.push_back({y, x});
    }

    sort(bars.begin(), bars.end(), greater<>());

    int result = bars[0].first;
    int left = bars[0].second;
    int right = bars[0].second + 1;

    for(int i = 1; i < n; i++){
        if(left > bars[i].second){
            result += bars[i].first * (left - bars[i].second);
            left = bars[i].second;
        }
        if(right <= bars[i].second){
            result += bars[i].first * (bars[i].second + 1 - right);
            right = bars[i].second + 1;
        }
    }

    cout << result;

    return 0;
}