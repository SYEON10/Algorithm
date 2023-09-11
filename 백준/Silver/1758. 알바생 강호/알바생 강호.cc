#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정의 : 팁을 최대한 많이 가져갈 수 있도록

bool compare_down(int a, int b){
    return a > b;
}

int main(){

    int n;
    long long count = 0;

    cin >> n;
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare_down);

    for(int i = 0; i < n; i++){
        if(v[i] - i <= 0)
            break;
        count += v[i] - i;
    }

    cout << count;

    return 0;
}