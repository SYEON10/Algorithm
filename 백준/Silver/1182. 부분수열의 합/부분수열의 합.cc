#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;
long long count = 0;
long long n, s;

void Calculate(long long pointer, long long add){
    //다 넣어봤음 종료
    if(pointer == n){
        if(s == add){
            count++;
        }
        return;
    }

    //안 넣는 경우
    Calculate(pointer + 1, add);
    //넣는 경우
    Calculate(pointer + 1, add + nums[pointer]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    nums.assign(n, 0);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Calculate(0, 0);

    if(s == 0){
        count--;
    }

    cout << count;

    return 0;
}
