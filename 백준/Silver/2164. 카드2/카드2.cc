#include <iostream>
#include <deque>

using namespace std;

//실제로 저 일련의 과정을 수행해야 할 시 덱(front, back 모두에 연산이 존재)

int main(){

    int n;
    cin >> n;

    deque<int> cards;

    for(int i = 1; i <= n; i++)
        cards.push_back(i);

    while(cards.size() != 1){
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }

    cout << cards[0];

    return 0;
}