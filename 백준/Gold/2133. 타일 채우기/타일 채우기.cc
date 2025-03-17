#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //DP[i] = n이 i일 때의 경우의 수
    vector<int> DP(n + 1, 0);

    //2칸짜리 블록 3종류, 2m칸짜리 블록이 2종류씩
    DP[0] = 1;
    DP[2] = 3;

    //DP[i] = for i to j -= 2 DP[j] + 2
    for(int i = 4; i <= n; i += 2){
        DP[i] = DP[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2){
            DP[i] += DP[j] * 2;
        }
    }

    cout << DP[n];

    return 0;
}