#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 7;

int n, m;
vector<int> num(SIZE);

void backtracking(int count){
    if(count == m){
        for(int i = 0; i < count; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        num[count] = i;
        backtracking(count+1);
    }

}

int main()
{
    cin >> n >> m;

    backtracking(0);

    return 0;
}