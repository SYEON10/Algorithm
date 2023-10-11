#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        if(m % i == 0 && (i + (m / i)) * 2 + 4 == n){
            cout << (m / i + 2) << ' ' << (i + 2);
            break;
        }
    }

    return 0;
}