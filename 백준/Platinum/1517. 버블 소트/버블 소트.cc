#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//버블 소트 = O(n^2)
//n <= 5 * 1e5
//알고리즘 최대 시간복잡도 O(nlogn)
//스왑 수 = 역순 수
//특정 구간 내 숫자가 앞에 나온 수

const int SIZE = 5000000;
vector<int> segtree(2 * SIZE, 0);

int Query(int left, int right, int index, int start, int end){
    if(right < start || left > end) return 0;
    if(left <= start && right >= end) return segtree[index];
    int mid = (start + end) / 2;
    return Query(left, right, index * 2, start, mid) + Query(left, right, index * 2 + 1, mid + 1, end);
}

void Update(int target, int index, int start, int end){
    if(start == end){
        segtree[index] = 1;
        return;
    }
    int mid = (start + end) / 2;
    if(target <= mid) Update(target, index * 2, start, mid);
    else Update(target, index * 2 + 1, mid + 1, end);
    segtree[index] = segtree[index * 2] + segtree[index * 2 + 1];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    long long result = 0;

    vector<pair<int, int>> nums(n);

    for(int i = 0; i < n; i++){
        nums[i].second = i + 1;
        cin >> nums[i].first;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        int num = nums[i].second;
        Update(num, 1, 1, n);
        result += Query(num + 1, n, 1, 1, n);
    }

    cout << result;

    return 0;
}