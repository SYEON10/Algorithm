#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> result(SIZE);
vector<int> checker(SIZE);
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
        if(!checker[i]){
            result[count] = num[i];
            checker[i] = true;
            backtracking(count+1);
            checker[i] = false;
        }
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