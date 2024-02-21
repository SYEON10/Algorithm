#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> DP;
int min_val = INT_MAX;

void Calculate(int n, int use){
    if(n == 1){
        if(use == 1) min_val = min(min_val, DP[n + 1]);
        else min_val = min(min_val, DP[n * use]);
        return;
    }

    if(DP[n] > min_val){
        return;
    }

    //3으로 나누어 떨어지면 나눈다
    if(n%3 == 0){
        DP[n/3] = DP[n] + 1;
        Calculate(n/3, 3);
    }
    //2로 나누어 떨어지면 나눈다
    if(n%2 == 0){
        DP[n/2] = DP[n] + 1;
        Calculate(n/2, 2);
    }
    //1을 뺀다
    DP[n - 1] = DP[n] + 1;
    Calculate(n - 1, 1);
}

int main() {

    int n;
    cin >> n;

    DP.assign(n+1, 1);

    Calculate(n, 1);

    cout << min_val;

    return 0;
}