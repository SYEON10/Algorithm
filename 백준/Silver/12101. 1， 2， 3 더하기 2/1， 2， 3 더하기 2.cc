#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int num = 0;
int cnt = 0;
vector<int> nums(11, 0);

bool back(int index){
    if(num == n){
        cnt++;
        if(cnt == k){
            cout << nums[0];
            for(int i = 1; i < index; i++){
                cout << '+' << nums[i];
            }
            return true;
        }
        return false;
    }
    if(num > n){
        return false;
    }

    for(int i = 1; i <= 3; i++){
        num += i;
        nums[index] = i;
        if(back(index + 1)) return true;
        num -= i;
    }
    return false;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> k;

    back(0);
    if(cnt != k){
        cout << -1;
    }

    return 0;
}