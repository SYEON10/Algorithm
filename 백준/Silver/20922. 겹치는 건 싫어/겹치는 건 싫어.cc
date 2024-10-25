#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    int a[100001] = {0};


    for(int i = 0; i < n; i ++){
        cin >> numbers[i];
    }

    int left = 0;
    int right = 0;
    int max_length = 0;

    while(left <= right && right < n){
        if(a[numbers[right]] < m){
            a[numbers[right]]++;
            right++;
            max_length = max(max_length, right - left);
        }
        else if (a[numbers[right]] == m){
            a[numbers[left]]--;
            left++;
        }
    }

    cout << max_length;

    return 0;
}