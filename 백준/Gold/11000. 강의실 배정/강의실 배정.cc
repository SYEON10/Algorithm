#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    if(p1.first != p2.first){
        return p1.first < p2.first;
    }
    else return p1.second < p2.second;
}

bool cmp2(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second < p2.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> lectures(n); //강의 시작하는 시간, 끝나는 시간
    priority_queue<int, vector<int>, greater<>> earlyEnd;

    for(int i = 0; i < n; i++){
        cin >> lectures[i].first >> lectures[i].second;
    }

    int minIndex = int(min_element(lectures.begin(), lectures.end(), cmp2) - lectures.begin());

    earlyEnd.push(lectures[minIndex].second);

    swap(lectures[minIndex], lectures.back());
    lectures.pop_back();

    sort(lectures.begin(), lectures.end(), cmp);

    for(int i = 0; i < n - 1; i++){
        if(lectures[i].first >= earlyEnd.top()){
            earlyEnd.pop();
        }
        earlyEnd.push(lectures[i].second);
    }

    cout << earlyEnd.size();

    return 0;
}