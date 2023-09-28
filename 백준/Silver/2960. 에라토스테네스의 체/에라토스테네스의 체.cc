#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    //1단계
    vector<bool> nums(n + 1, true);

    nums[0] = false;
    nums[1] = false;

    while(true){
        int p = 0;
        //2단계
        for(int i = 2; i <= n; i++){
            if(nums[i]){
                p = i;
                break;
            }
        }
        //3단계
        for(int j = 1; p * j <= n; j++){
            if(nums[p * j]){
                nums[p * j] = false;
                k--;
            }
            if(k == 0){
                cout << p * j;
                return 0;
            }
        }
    }

    return 0;
}