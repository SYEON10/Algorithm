#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    double n;
    cin >> n;

    vector<double> input(n);
    double sum = 0;

    for(int i = 0; i < n; i++){
        cin >> input[i];
        sum += input[i];
    }

    double max_value = *max_element(input.begin(), input.end());
    max_value = 100.0 / max_value;

    cout << sum * max_value / n;
    
    return 0;
}