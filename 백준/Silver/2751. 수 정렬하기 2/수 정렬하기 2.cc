#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    vector<int> input;
    input.assign(count, 0);

    for(int i = 0; i < count; i++){
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    for (int i = 0; i < count; i++) {
        cout << input[i] << '\n';
    }

    return 0;
}