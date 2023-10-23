#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MIN = -1e9, MAX = 1e9;

int n, minValue = MAX, maxValue = MIN;
vector<int> nums;
vector<int> operators(4);


void Backtracking(int idx, int sum){
    if(idx == n - 1){
        minValue = std::min(minValue, sum);
        maxValue = std::max(maxValue, sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            int sumUpdate = 0;
            switch(i){
                case 0:
                    sumUpdate = sum + nums[idx + 1];
                    break;
                case 1:
                    sumUpdate = sum - nums[idx + 1];
                    break;
                case 2:
                    sumUpdate = sum * nums[idx + 1];
                    break;
                case 3:
                    sumUpdate = sum / nums[idx + 1];
                    break;
            }
            Backtracking(idx + 1, sumUpdate);
            operators[i]++;
        }
    }
}

int main() {

    cin >> n;

    nums.assign(n, 0);

    for(auto &num : nums)
        cin >> num;

    for(auto &oper : operators){
        cin >> oper;
    }

    Backtracking(0, nums[0]);

    cout << maxValue << '\n' << minValue;

    return 0;
}