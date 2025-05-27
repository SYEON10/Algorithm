#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//items 내에서 합이 c가 되는 두 수 찾기
bool TwoPointer(const vector<int>& items, int c, int right){
    int left = 0;
    while(left < right){
        int sum = items[left] + items[right];

        if(sum == c) return true;
        if(sum > c){
            right--;
        }
        if(sum < c){
            left++;
        }
    }
    return false;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    int n, c;
    cin >> n >> c;

    vector<int> items(n);

    for(int i = 0; i < n; i++){
        cin >> items[i];
    }

    sort(items.begin(), items.end());

    //1개(O(N))
    for(int i = n - 1; i >= 0; i--){
        if(items[i] < c) break;
        if(items[i] == c) {
            cout << 1;
            return 0;
        }
    }

    if(TwoPointer(items, c, items.size() - 1)){
        cout << 1;
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(TwoPointer(items, c - items[i], i - 1)){
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}