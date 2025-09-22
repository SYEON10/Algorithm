#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    long long n;
    cin >> n;

    //1 3 4 9 10 12 13 27...
    //2 ^ k개 만큼 생김
    //4 < 7 < 8
    //9 + 3 + 1
    //7을 비트바스킹하면
    //0111

    long long curr = 1;
    long long result = 0;

    //0 1 0 0
    
    for(long long i = 0; i < 64; i++){
        if(n & (1LL << i)){
            result += curr;
        }
        curr *= 3;
    }

    cout << result;

    return 0;
}