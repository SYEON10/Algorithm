#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CountRouter(const vector<int> &pos, int distance){ //위치, 거리
    int count = 1;
    int beforeRouter = pos[0];
    for(int i = 1; i < pos.size(); i++){
        if(pos[i] - beforeRouter >= distance){
            beforeRouter = pos[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> housePos(n);
    for(auto &pos : housePos){
        cin >> pos;
    }

    sort(housePos.begin(), housePos.end());

    int left = 1;
    int right = housePos.back() - housePos.front();
    int mid;

    while(left <= right){
        mid = (right + left) / 2;

        int count = CountRouter(housePos, mid);

        if(count >= c){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << left - 1;

    return 0;
}