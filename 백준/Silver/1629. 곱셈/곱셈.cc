#include <iostream>
#include <cmath>

using namespace std;

long long PrintResult(long long a, long long b, long long c){
    if(b == 1) return a % c;
    long long val = PrintResult(a, b/2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << PrintResult(a, b, c);

    return 0;
}
