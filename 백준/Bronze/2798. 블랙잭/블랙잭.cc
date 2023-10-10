#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m, result = 0;
    cin >> n >> m;

    vector<int> cards(n);

    for(int i = 0; i < n; i++)
        cin >> cards[i];

    vector<bool> index(n, false);
    for(int i = 0; i < 3; i++)
        index[i] = true;

    do{
        int add = 0;
        for(int i = 0; i < n; i++){
            if(index[i])
                add += cards[i];
        }

        if(add <= m)
            result = m - add > m - result ? result : add;

    }while(std::prev_permutation(index.begin(), index.end()));

    cout << result;

    return 0;
}