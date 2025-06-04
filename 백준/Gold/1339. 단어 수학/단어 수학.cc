#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

/* 1339 단어 수학
1. 자릿수대로 가중치 부여
2. 숫자 매핑 및 sum
*/

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    map<char, int> m;

    while (n--) {
        string input;
        cin >> input;
        int length = input.size();
        for (int i = 0; i < length; i++) {
            m[input[i]] += pow(10, length - i - 1);
        }
    }

    vector<int> alpha;
    for (auto& a : m) {
        alpha.push_back(a.second);
    }

    sort(alpha.begin(), alpha.end(), greater<>());

    int sum = 0;
    int i = 9;
    for (int a : alpha) {
        sum += a * i;
        i--;
    }

    cout << sum;

    return 0;
}