#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    //인수분해를 해서 소수의 개수를 셈
    //소수의 개수의 절반

    //1. 소수를 찾는다.
    //2. 소수로 인수의 수를 센다
    //3. 계산

    int n;
    cin >> n;

    int max = n / 2;
    bool arr[n/2 + 1] = {false};
    int count = 0;

    for(int i = 2; i * i <= max; i++){
        if(!arr[i]){
            for(int j = i * i; j <= max; j+= i){
                arr[j] = true;
            }
        }
    }

    for(int i = 2; i <= max; i++){
        if(!arr[i]) {
            while(n % i == 0){
                n /= i;
                count++;
            }
        }
    }

    int result = 0;

    while(count > 1){
        if(count % 2 == 1){//홀수면
            count++;
        }

        count /= 2;
        result++;
    }

    cout << result;

    return 0;
}