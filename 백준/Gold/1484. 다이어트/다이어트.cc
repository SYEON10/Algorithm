#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long g;
    cin >> g;

    //코너케이스 : 몸무게가 3보다 작을 때
    if(g < 3){
        cout << -1;
        return 0;
    }

    vector<long long> squares(g + 1);

    for(long long i = 1; i <= g; i++)
        squares[i] = i * i;

    long long left = 1, right = 2;
    bool isPossible = false;

    while(left < right){
        long long result = squares[right] - squares[left];

        if(result == g){
            cout << right << '\n';
            right++;
            isPossible = true;
        }
        if(result < g){
            right++;
        }
        if(result > g){
            left++;
        }
    }

    //코너케이스 : 가능한 몸무게가 없을 때 -1
    if(!isPossible)
        cout << -1;

    return 0;
}