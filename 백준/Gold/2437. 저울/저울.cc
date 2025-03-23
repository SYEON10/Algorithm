#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Calculate(const vector<int>& table){
    int n = table.size();

    if(table[0] != 1) {
        return 1;
    }

    int num = 1;
    for(int i = 1; i < n; i++){
        if(table[i] > num + 1) 
            return num + 1;

        num += table[i];
    }

    return num + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> table(n);

    for(int i = 0; i < n; i++){
        cin >> table[i];
    }

    sort(table.begin(), table.end());

    cout << Calculate(table);

    return 0;
}