//
// Created by syeon on 2023-09-29.
//

// @@실패@@

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//해당 숫자의 홀수 합 모음...
//3 + 5
//3 + 17
//3 + 39
//5 + 37

//이런식이 최선일 것 같다.
//필요 알고리즘 : 소수 판별 알고리즘 -> 에라토스테네스의 체

//혹은 백만 이하의 모든 소수를...

vector<bool> is_prime(1000001, true);

void PrimeTableSetting(int num){

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= sqrt(num); i++){
        if(is_prime[i]){
            for(int j = 2 * i; j <= num; j += i){
                is_prime[j] = false;
            }
        }
    }

}

bool isPrime(int num){
    return is_prime[num];
}

void Calculator(int num){

    int a = 1, b;

    while(a <= num){
        a += 2;

        b = num - a;

        if(isPrime(a) && isPrime(b)){
            cout << num << " = " << a << " + " << b << '\n';
            break;
        }
    }

    if(a > num)
        cout << "Goldbach's conjecture is wrong." << '\n';

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;

    PrimeTableSetting(1000000);

    while(cin >> num){
        if(num == 0)
            return 0;
        Calculator(num);
    }

    return 0;
}