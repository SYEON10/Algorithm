#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//최대 nlogn
//최종 점수는 = 카드 중에 내 배수 - 카드 중에 내 약수
//에라토스테네스의 체 방식 응용... => 구하고자 하는 범위의 루트까지만 하면 됨...

int MAX = 1000'000;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> cards(n);
    vector<int> board(MAX + 1, 0); //cards에 내 약수가 몇갠지...
    vector<bool> isInCards(MAX + 1, false);
    vector<int> result(n, 0);
    
    for(int i = 0; i < n; i++){
        cin >> cards[i];
        isInCards[cards[i]] = true;
    }

    for(int i = 0; i < n; i++){
        int num = cards[i];
        int mul = 2;
        while(num * mul <= MAX){
            board[num * mul]++;
            if(isInCards[num * mul]){
                result[i]++;
            }
            mul++;
        }
    }

    for(int i = 0; i < n; i++){
        cout << result[i] - board[cards[i]] << ' ';
    }

    return 0;
}