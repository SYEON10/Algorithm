#include <iostream>
#include <cmath>

using namespace std;

int count = 0;

void Search(int n, int r, int c){
    if(n == 1){
        count += r * 2 + c;
        cout << count;
        return;
    }

    int checker = pow(2, n - 1);
    int newR, newC;

    if(r >= checker) {
        newR = r - checker;
        count += checker * checker * 2;
    }
    else newR = r;

    if(c >= checker){
        newC = c - checker;
        count += checker * checker;
    }
    else newC = c;

    Search(n - 1, newR, newC);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;

    Search(n, r, c);

    return 0;
}
