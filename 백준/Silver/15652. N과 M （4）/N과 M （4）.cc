#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> num(SIZE);

void backtracking(int count, int start){
    if(count == m){
        for(int i = 0; i < count; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }


    for(int i = start; i <= n; i++){
        num[count] = i;
        backtracking(count+1, i);
    }

}

int main()
{
    cin >> n >> m;

    backtracking(0, 1);

    return 0;
}