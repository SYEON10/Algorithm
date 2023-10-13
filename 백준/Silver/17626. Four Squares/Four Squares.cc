#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> table;

int Checker(int n){
    if(n == table.back())
        return 1;

    for(int i = 0; i < table.size(); i++){
        for(int j = i; j < table.size(); j++){
            if(table[i] + table[j] == n)
                return 2;
        }
    }

    for(int i = 0; i < table.size(); i++){
        for(int j = i; j < table.size(); j++){
            for(int k = j; k < table.size(); k++){
                if(table[i] + table[j] + table[k] == n)
                    return 3;
            }
        }
    }

    return 4;
}

int main(){

    //입력
    int n;
    cin >> n;

    //테이블 생성

    for(int i = 1; i <= sqrt(n); i++){
        table.push_back(int(pow(i, 2)));
    }

    //출력

    cout << Checker(n);

    return 0;
}