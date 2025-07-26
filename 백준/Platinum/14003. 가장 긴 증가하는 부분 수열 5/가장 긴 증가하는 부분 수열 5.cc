#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//LIS 문제
//DP만 사용한 풀이 O(N^2)
//이분탐색 사용 시 O(NLogN)

int main()
{
    int n;
    cin >> n;

    vector<int> A(n, 0);
    //가장 긴 증가하는 부분 수열
    vector<int> LIS(n + 1, INT32_MIN);
    vector<int> DP(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int end = 0;

    //제일 큰 수면 뒤에 추가, 아니면 다음으로 큰 수 대체
    for (int i = 0; i < n; i++) {
        if (LIS[end] < A[i]) {
            LIS[++end] = A[i];
            DP[i] = end;
            continue;
        }

        //정렬 상태에서의 탐색이므로 이분탐색 사용

        int left = 0;
        int right = end;

        while (left < right) {
            int mid = (left + right) / 2;
            if (LIS[mid] < A[i]) {
                left = mid + 1;
            }
            else right = mid;
        }
        LIS[right] = A[i];
        DP[i] = right;
    }

    vector<int> ans(end + 1);

    int cur_i = end;
    for (int i = n - 1; i >= 0; i--) {
        if (DP[i] == cur_i) {
            ans[cur_i--] = A[i];
        }
    }

    cout << end << '\n';

    for (int i = 1; i <= end; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}