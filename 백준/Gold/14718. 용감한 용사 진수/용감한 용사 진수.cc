#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int SIZE = 101;
const int POINT_MAX= 3000'001;

int n, k;
int board[SIZE][3];

//point가 주어졌을 때 이길 수 있는 최대 병사 수가 K보다 같거나 큰지
bool Simulate(int point){
    for(int pow = 0; pow < n; pow++){
        for(int speed = 0; speed < n; speed++){
                int curr_pow = board[pow][0];
                int curr_speed = board[speed][1];
                int curr_intel = point - curr_pow - curr_speed;

                int count = 0;

                for(int i = 0; i < n; i++){
                    if(board[i][0] <= curr_pow && board[i][1] <= curr_speed && board[i][2] <= curr_intel){
                        count++;
                    }
                }

                if(count >= k){
                    return true;
                }
        }
    }

    return false;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    int left = 0;
    int right = POINT_MAX;

    while(left < right){
        int mid = (left + right) / 2;

        if(Simulate(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << right;

    return 0;
}