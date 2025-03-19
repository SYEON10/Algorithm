#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> table;
vector<bool> check;
int n, m;

void print(){
    for(int i = 1; i <=m ; i++){
        cout << table[i] << ' ';
    }
    cout << '\n';
}

void BackTracking(int index){
    if(index == m){
        print();
        return;
    }

    for(int num = 1; num <= n; num++){
        if(table[index] == num || check[num]){
            continue;
        }
        table[index + 1] = num;
        check[num] = true;
        BackTracking(index + 1);
        check[num] = false;
    }
}

int main()
{
    cin >> n >> m;

    table.assign(m + 1, 0);
    check.assign(m + 1, false);

    BackTracking(0);

    return 0;
}