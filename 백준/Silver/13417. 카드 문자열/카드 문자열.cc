#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<char> str(n);
        deque<char> result;

        for(int i = 0; i < n; i++){
            cin >> str[i];
        }

        result.push_back(str[0]);

        for(int i = 1; i < n; i++){
            (result.front() >= str[i]) ? result.push_front(str[i]) : result.push_back(str[i]);
        }

        for(int i = 0; i < n; i++){
            cout << result[i];
        }

        cout << '\n';
    }

    return 0;
}