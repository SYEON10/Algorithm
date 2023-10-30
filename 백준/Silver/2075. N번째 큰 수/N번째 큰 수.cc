#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> table;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            table.push(x);
            if(table.size() > n){
                table.pop();
            }
        }
    }

    while(table.size() == 1){
        table.pop();
    }

    cout << table.top();

    return 0;
}