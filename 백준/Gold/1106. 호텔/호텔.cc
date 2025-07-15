#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE = 1000 * 100;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int c, n;
    cin >> c >> n;
    
    //index: cost
    vector<int> DP(SIZE + 1, 0);
    vector<pair<int, int>> ad(n);

    for(int i = 0; i < n; i++){
        int cost, num;
        cin >> cost >> num;
        ad[i] = {cost, num};

        //일단 쭉 넣을 수 있는대로 넣어두기
        for(int j = 1; j <= (c / num) + 1; j++){
            DP[j * cost] = max(DP[(j - 1) * cost] + num, DP[j * cost]);
        }
    }

    for(int i = 0; i < n; i++){
        int cost = ad[i].first;
        int num = ad[i].second;
        //num이 C를 넘을 때까지 DP에 넣기 + 중복이 있어도 무관
        for(int j = cost; j <= SIZE - cost; j++){
            DP[j + cost] = max(DP[j] + num, DP[j + cost]);
            if(DP[j + cost] >= c) break;
        }
    }

    for(int i = 1; i <= SIZE; i++){
        if(DP[i] >= c) {
            cout << i;
            return 0;
        }
    }

    return 0;
}