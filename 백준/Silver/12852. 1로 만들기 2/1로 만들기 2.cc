#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //i의 최소 연산 횟수
    vector<int> DP(n + 1, 0);
    vector<int> path(n + 1, 0);

    //DP[i] = min(DP[i / 3], DP[i / 2], DP[i - 1]) + 1;

    for(int i = 2; i <= n; i++){
        int value = DP[i - 1];
        path[i] = i - 1;

        if(i % 3 == 0 && DP[i / 3] < value){
            value = DP[i / 3];
            path[i] = i / 3;
        }

        if(i % 2 == 0 && DP[i / 2] < value){
            value = DP[i / 2];
            path[i] = i / 2;
        }

        DP[i] = value + 1;
    }

    cout << DP[n] << '\n';

    int before = n;
    while(before >= 1){
        cout << before << ' ';
        before = path[before];
    }

    return 0;
}