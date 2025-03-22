#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//시간복잡도 - O(k^2) (max_element로 풀 시)

void Calculate(vector<int>& num, int n, int k){
    //WIP
    //Goal: 앞에 나보다 작은 숫자 없도록 만들기

    deque<int> deq;
    int count = 0;

    for(int i = 0; i < n; i++){
        while(count < k && !deq.empty() && deq.back() < num[i]){
            deq.pop_back();
            count++;
        }
        deq.push_back(num[i]);
    }

    for(int i = 0; i < n - k; i++){
        cout << deq.front();
        deq.pop_front();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    string input;
    cin >> input;

    vector<int> num(n, 0);

    for(int i = 0; i < n; i++){
        num[i] = input[i] - '0';
    }

    Calculate(num, n, k);

    return 0;
}