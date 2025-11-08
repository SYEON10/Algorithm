#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

//O(nlogn) 최대
//1 2 3 4 5 6 7
//2 5 3 7 4 6 1

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> temp(n);
    vector<int> nums(n + 1);

    for(int i = 0; i < n; i++){
        cin >> temp[i].first;
        temp[i].second = i;
    }
    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++){
        nums[i] = temp[i].second;
    }

    vector<bool> visited(n + 1, false);
    int count = 0;

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        count++;
        for(int num = nums[i]; num != i;num = nums[num]){
            visited[num] = true;
        }
    }

    cout << n - count;

    return 0;
}