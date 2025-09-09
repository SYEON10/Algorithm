#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//최대 O(nlogn)

//경로가 필요하고, 그 경로가 최소 길이/사전순
//주어진 재료(금민수)로 목표합 달성 + 경로 => DP 역추적

//저장되어야 하는 것 : 최소 길이, 마지막으로 사용된 금민수

//DP[i] = min(DP[i], DP[i - x]) : 이때, x는 모든 금민수
//Prev[i] = x (사용된 마지막 금민수)

const int MAX = 1e9;

int target;
vector<int> minsu;

void MinsuCreator(int num, int digit){
    if(num > target) return;
    minsu.push_back(num);
    MinsuCreator(num + digit * 4, digit * 10);
    MinsuCreator(num + digit * 7, digit * 10);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> target;

    if(target < 0) cout << -1;

    vector<int> DP(target + 1, MAX);
    vector<int> prev(target + 1, -1);

    DP[0] = 0;

    //금민수 만들기
    MinsuCreator(4, 10);
    MinsuCreator(7, 10);

    sort(minsu.begin(), minsu.end());

    for(int i = 1; i <= target; i++){
        for(int mu : minsu){
            if(i < mu) break;
            if(DP[i] > DP[i - mu] + 1){ //수의 개수가 적은 것 && 사전순으로 앞서는 것 
                DP[i] = DP[i - mu] + 1;
                prev[i] = mu;
            }
        }
    }

    if(DP[target] == MAX){
        cout << -1;
        return 0;
    }

    int curr = target;
    vector<int> result;
    while(prev[curr] > 0){
        result.push_back(prev[curr]);
        curr = curr - prev[curr];
    }

    sort(result.begin(), result.end());

    for(int r : result){
        cout << r << ' ';
    }

    return 0;
}