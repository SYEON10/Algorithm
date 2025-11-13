#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<int> counter(26, 0);

    string str;
    cin >> str;

    int count = 0;

    for(int i = 0; i < str.length(); i++){
        int left = i;
        int right = str.length() - 1;
        bool check = false;
        while(left <= right){
            if(str[left] != str[right]) {
                check = true;
                break;
            }
            left++;
            right--;
        }
        if(!check){
            count = i;
            break;
        }
    }

    cout << str.length() + count;

    return 0;
}