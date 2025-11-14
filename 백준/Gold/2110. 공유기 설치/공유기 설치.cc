#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

//설치된 공유기 최대 개수 반환
vector<int> houses;

int Simulate(int dist){
    int count = 1;
    int prev = houses[0];
    for(int i = 1; i < houses.size(); i++){
        if(houses[i] - prev >= dist){
            count++;
            prev = houses[i];
        }
    }

    return count;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, c;
    cin >> n >> c;

    houses.assign(n, 0);

    for(int i = 0; i < n; i++){
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int left = 1;
    int right = houses[n - 1] - houses[0] + 1;

    while(left < right){
        int mid = (left + right) / 2;

        if(Simulate(mid) >= c){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    cout << right - 1;

    return 0;
}