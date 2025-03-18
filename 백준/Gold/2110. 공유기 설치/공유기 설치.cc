#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_count(vector<int> &house, int distance) {
    int count = 1;
    int before_house = 0;
    for(int i = 1; i < house.size(); i++) {
        if(house[i] - house[before_house] >= distance) {
            before_house = i;
            count++;
        }
    }

    return count;
}

int main() {

    int n, c;

    cin >> n >> c;

    vector<int> house(n);

    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int left = 1;
    int right = house.back() - house.front();

    while(left <= right) {
        int mid = (left + right) / 2;
        int count = max_count(house, mid);

        if(count >= c) {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << left - 1;

}