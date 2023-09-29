#include <iostream>
#include <algorithm>

using namespace std;

string mircoNum(string num){

    bool isTen = false;
    int sum = 0;

    for(auto n : num){
        sum += n - '0';
        if(n == '0')
            isTen = true;
    }

    if(sum %3 != 0 || !isTen)
        return "-1";

    sort(num.begin(), num.end(), greater<>());

    return num;
}

int main(){

    string num;
    cin >> num;

    cout << mircoNum(num);

    return 0;
}