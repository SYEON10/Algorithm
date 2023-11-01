//
// Created by syeon on 2023-11-01.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> lectures(n); //강의 시작하는 시간, 끝나는 시간
    priority_queue<int, vector<int>, greater<>> earlyEnd;

    for(int i = 0; i < n; i++){
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end());
    
    earlyEnd.push(-1);

    for(int i = 0; i < n; i++){
        if(lectures[i].first >= earlyEnd.top()){
            earlyEnd.pop();
        }
        earlyEnd.push(lectures[i].second);
    }

    cout << earlyEnd.size();

    return 0;
}