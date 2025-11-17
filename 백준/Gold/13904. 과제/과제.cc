#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int values[1001];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int, int>> assignment(n);

    for(int i = 0; i < n; i++){
        cin >> assignment[i].second >> assignment[i].first;
    }

    sort(assignment.begin(), assignment.end(), greater<>());

    int result = 0;
    for(auto[value, time] : assignment){
        for(int i = time; i > 0; i--){
            if(values[i] != 0) continue;
            values[i] = value;
            result += value;
            break;
        }
    }

    cout << result;

    return 0;
}