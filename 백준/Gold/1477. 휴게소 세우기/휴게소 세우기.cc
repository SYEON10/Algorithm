#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//코너케이스 : 현재 지어진 휴게소가 없을 수 있음

//최대 거리, 고속도로 끝, 현재 설치된 휴게소
int MoreRestArea(int moreRest, int maxDist, int maxLeng, const vector<int> &RestPos){
    int count = 0;

    for(int i = 1; i < RestPos.size(); i++){
        count += (RestPos[i] - RestPos[i - 1] - 1) / maxDist;
    }
    /*
    int currentPos = 1;

    if(!RestPos.empty()){
        count += (maxLeng - RestPos.back()) / (maxDist);
        count += (RestPos[0] - currentPos)/ (maxDist);
        currentPos = RestPos[0];
    }else{
        count += (maxLeng - currentPos) / (maxDist);
    }

    for(int i = 1; i < RestPos.size(); i++){
        count += ((RestPos[i] - 1 - currentPos) / (maxDist));
        currentPos = RestPos[i];
        if(count > moreRest){
            return count;
        }
    }

     */
    return count;
}

int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> currentRestPos(n + 2, 0);

    for(int i = 1; i <= n; i++){
        cin >> currentRestPos[i];
    }
    currentRestPos[n + 1] = l;

    sort(currentRestPos.begin(), currentRestPos.end());

    int mid, left = 1, right = l - 1;

    while(left <= right){
        mid = (right + left) / 2;

        if(MoreRestArea(m, mid, l, currentRestPos) <= m) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}