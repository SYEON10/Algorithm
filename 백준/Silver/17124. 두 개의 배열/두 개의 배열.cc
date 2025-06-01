#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void DoSomething() {
    int n, m;
    cin >> n >> m;

    vector<long long> A(n);
    vector<long long> B(m);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    //무식하게 하면 O(nm)으로 최대 10^12 -> 시간초과 O
    //이분탐색이면 nlogm

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = m - 1;

        //A[i]보다 큰 B를 찾는 것
        while (left < right) {
            int mid = (left + right) / 2;

            if (A[i] > B[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (right == 0) {
            sum += B[0];
            continue;
        }

        if (B[right] - A[i] < abs(A[i] - B[right - 1])) {
            sum += B[right];
        }
        else {
            sum += B[right - 1];
        }
    }

    cout << sum << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        DoSomething();
    }

    return 0;
}