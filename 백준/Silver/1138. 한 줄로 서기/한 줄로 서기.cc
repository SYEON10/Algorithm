#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

//1 2 3 4
//순서를 "거스른 사람"의 수
//뒤에서부터 앞으로 가면서 위치 조정하면 됨 문제는 중간삽입이 있다는 것...

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    int nums[n];
    deque<int> dq;
    stack<int> stk;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = n - 1; i >= 0; i--){
        while(nums[i]--){
            stk.push(dq.front());
            dq.pop_front();
        }
        dq.push_front(i + 1);
        while(!stk.empty()){
            dq.push_front(stk.top());
            stk.pop();
        }
    }

    for(int num : dq){
        cout << num << ' ';
    }

    return 0;
}