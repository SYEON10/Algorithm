#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main(){

    int W0, I0, T, D, I, A, B, W, ChangeW;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    B = I0;
    W = W0;

    //일일 기초 대사량 변화 고려 X

    W += D * (I - (A + B));

    if(W <= 0 || B <= 0)
        cout << "Danger Diet";
    else cout << W << " " << B;

    cout << '\n';

    //일일 기초 대사량 변화 고려 O

    W = W0;
    for(int i = 0; i < D; i++){
        ChangeW = I - (A + B);
        W += ChangeW;
        if(abs(ChangeW) > T)
            B += floor((double)ChangeW / 2);
    }

    if(W <= 0 || B <= 0)
        cout << "Danger Diet";
    else {
        cout << W << " " << B;

        ChangeW = I0 - (0 + B);

        if(ChangeW > 0)
            cout << " YOYO";
        else cout << " NO";
    }

    return 0;
}