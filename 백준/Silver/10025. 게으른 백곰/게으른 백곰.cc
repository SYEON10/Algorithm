//
// Created by syeon on 2023-11-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, x, y, minPos = 1e6, maxPos = 0;
    cin >> n >> k;

    vector<int> pos(1e6 + 1, 0); //idx : pos, val : weight

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pos[y] = x;
        minPos = min(minPos, y);
        maxPos = max(maxPos, y);
    }

    int maxWeight = 0, curWeight = 0, reach = k * 2;

    //윈도우 초기화

    for(int i = minPos;i <= (minPos + reach) && i <= maxPos; i++){
        curWeight += pos[i];
    }

    maxWeight = curWeight;

    for(int i = minPos + 1; i + reach < maxPos; i++){
        curWeight -= pos[i - 1];
        curWeight += pos[(i + reach)];
        maxWeight = max(curWeight, maxWeight);
    }

    cout << maxWeight;

    return 0;
}