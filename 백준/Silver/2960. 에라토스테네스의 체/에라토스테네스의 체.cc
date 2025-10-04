#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    bool arr[n + 1] = {};

    arr[0] = arr[1] = true;

    int p = 2;
    int count = 0;
    while(true){
            for(int i = 1; i <= n / p; i++){
        if(!arr[p * i]){
            arr[p * i] = true;
            count++;
            if(count == k){
                cout << p * i;
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] == false){
            p = i;
            break;
        }
    }
    }

    return 0;
}