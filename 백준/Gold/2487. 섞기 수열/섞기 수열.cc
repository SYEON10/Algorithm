#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

//닫힌 집합이고, 무조건 일대일 대응이기 때문에 전체는 어쨌건 사이클을 이룸
//사이클의 길이의 최소공배수를 구하는 문제

const int MAX = 20'001;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int next[MAX];

    int n;
    cin >> n;
    vector<bool> visited(n + 1, false);

    for(int i = 1; i <= n; i++){
        cin >> next[i];
    }

    int _lcm = 1;

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        long long count = 1;
        for(int j = i; next[j] != i; j = next[j]){
            count++;
            visited[next[j]] = true;
        }
        _lcm = lcm(_lcm, count);
    }

    cout << _lcm;

    return 0;
}