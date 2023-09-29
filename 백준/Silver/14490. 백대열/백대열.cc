#include <iostream>
#include <algorithm>

using namespace std;

//최대공약수로 각 수를 나누기

long long GCD(long long a, long long b){
    if(b == 0)
        return a;
    else return GCD(b, a % b);
}

long long CalculateGCD(long long a, long long b){

    if(a < b)
        swap(a, b);

    long long gcd = GCD(a, b);

    return gcd;
}

int main(){

    long long n, m, gcd;
    char tempChar;

    cin >> n >> tempChar >> m;

    gcd = CalculateGCD(n, m);

    cout << n / gcd << ':' << m / gcd;

    return 0;
}