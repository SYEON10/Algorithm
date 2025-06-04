#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
1. 음수에서의 연산과 양수에서의 연산은 거의 유사함 -> 함수로 만들면 됨
2. 1은 더할 때 더 이득임(곱했을 때 Not Good...) -> 코너케이스
*/

int Calculate(vector<int>& v){

    int sum = 0;
    int size = v.size();
    for(int i = 0; i < size - 1; i += 2){
        sum += v[i] * v[i + 1];
    }

    if(size % 2){
        sum += v[size - 1];
    }
    
    return sum;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, count = 0;
    cin >> n;

    vector<int> pos;
    vector<int> neg;

    //0도 고려해야 함

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a > 1){
            pos.push_back(a);
        }
        else if(a < 1){
            neg.push_back(a);
        }
        else{
            count++;
        }
    }

    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    int sum = count;
    sum += Calculate(pos);
    sum += Calculate(neg);

    cout << sum;

    return 0;
}