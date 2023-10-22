#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 10'000'000;
int n, minCost;
vector<vector<int>> map;
vector<int> checker;

//인자로 들어가야 하는 것들 : 바뀌어야 하고 재귀 내부에서 저장되어야 하는 것들(재귀를 통해 변화하는 값들)
void BackTracking(int idx, int currentCity, int cost){
    if(cost >= minCost){
        return;
    }
    if(idx == n){
        if(map[currentCity][0] != 0)
            minCost = min(minCost, cost + map[currentCity][0]);
        return;
    }
    for(int i = 0; i < n; i++){
        if(map[currentCity][i] != 0 && !checker[i]){
            checker[i] = true;
            BackTracking(idx + 1, i, cost + map[currentCity][i]);
            checker[i] = false;
        }
    }
}

int main() {

    cin >> n;

    checker.assign(n, false);
    minCost = MAX;

    vector<int> temp(n);
    for(int i = 0; i < n; i++){
        for(auto &t : temp){
            cin >> t;
        }
        map.push_back(temp);
    }

    checker[0] = true;
    BackTracking(1, 0, 0);

    cout << minCost;

    return 0;
}