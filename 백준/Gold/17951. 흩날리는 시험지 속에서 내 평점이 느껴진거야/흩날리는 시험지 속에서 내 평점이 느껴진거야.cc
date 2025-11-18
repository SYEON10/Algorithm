#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

//k가 나오는 최대 점수로 가시죠(Upper bound - 1)

int n, k;
int papers[100001];

int Simulate(int value){
    int cvalue = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        cvalue += papers[i];
        if(cvalue >= value){
            cvalue = 0;
            count++;
        }
    }

    return count;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> k;

    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> papers[i];
        sum += papers[i];
    }

    int left = 0;
    int right = sum + 1;

    while(left < right){
        int mid = (left + right) / 2;

        if(Simulate(mid) >= k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    cout << right - 1;

    return 0;
}