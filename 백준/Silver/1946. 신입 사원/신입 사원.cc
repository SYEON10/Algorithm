#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> test;

bool cmp(test a, test b){
    return a.first < b.first;
}

//서류 등수가 더 높은 사람들과 면접 점수를 비교

int Select(vector<test>& v){
    int count = 1;
    bool pass = true;

    sort(v.begin(), v.end(), cmp);

    int min = v[0].second;
    for(int i = 1; i < v.size(); i++){
        if(min > v[i].second){
            min = v[i].second;
            count++;
        }
    }

    return count;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<test> v;

    int count, n;
    cin >> count;

    while(count--){
        cin >> n;
        v.assign(n, {0,0});

        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }

        cout << Select(v) << '\n';
    }

    return 0;
}