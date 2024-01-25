//
// Created by syeon on 2024-01-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> result(SIZE);
vector<int> num;

void backtracking(int count){
    if(count == m){
        for(int i = 0; i < count; i++){
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i = 0; i < n; i++){
            result[count] = num[i];
            backtracking(count+1);
    }

}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }

    sort(num.begin(), num.end());

    backtracking(0);

    return 0;
}