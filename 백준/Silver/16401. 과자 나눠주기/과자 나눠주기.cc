#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SnackCutter(int length, const vector<int> &snacks){
    int count = 0;
    for(const auto& snack : snacks){
        if((snack / length) == 0){
            break;
        }
        count += snack / length;
    }

    return count;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> snacks(n);

    for(auto &snack : snacks){
        cin >> snack;
    }

    sort(snacks.begin(), snacks.end(), greater<>());

    int mid, left = 1, right = snacks[0];

    while(left <= right){
        mid = (right + left) / 2;

        if(SnackCutter(mid, snacks) >= m){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << left - 1;
    //코너케이스 : 같은 길이의 막대과자를 나눠줄 수 없는 경우도 있다.

    return 0;
}