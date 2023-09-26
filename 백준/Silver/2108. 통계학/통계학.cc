#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}

int findMode(const vector<int>& v){

    int mode;
    map<int, int> sortMap; //정수값, 정수 개수

    for(auto in : v){
        sortMap[in]++;
    }
    vector<pair<int, int>> count(sortMap.begin(), sortMap.end());

    sort(count.begin(), count.end(), cmp);

    if(count[0].second == count[1].second){
        return count[1].first;
    }

    return count[0].first;
}

int main(){

    int n, median = 0, sum = 0, range = 0;
    cin >> n;

    vector<int> numbers;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        numbers.push_back(x);
        sum += x;
    }

    sort(numbers.begin(), numbers.end());

    median = numbers[numbers.size()/2];
    range = numbers[numbers.size() - 1] - numbers[0];

    cout << floor(double(sum) / n + 0.5) << '\n';
    cout << median<< '\n';
    cout << findMode(numbers)<< '\n';
    cout << range<< '\n';

    return 0;
}