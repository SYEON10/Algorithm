#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> days(n);
    for(auto &day : days){
        cin >> day;
    }

    vector<int> windows(n - x + 1);

    for(int i = 0; i < x; i++){
        windows[0] += days[i];
    }

    for(int i = 1; i < windows.size(); i++){
        windows[i] = windows[i - 1] + days[i + x - 1] - days[i - 1];
    }

    sort(windows.begin(), windows.end(), greater<>());


    if(windows[0] != 0){
        int count = 1;
        for(int i = 1; i <  windows.size(); i++){
            if(windows[i] == windows[0]){
                count++;
            }
            else break;
        }

        cout << windows[0] << '\n';
        cout << count;
    }
    else cout << "SAD";

    return 0;
}