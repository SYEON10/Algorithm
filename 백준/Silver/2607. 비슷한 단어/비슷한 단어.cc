#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Calculate(vector<int> compare, string input, int n){

    if(abs(n - (int)input.size()) > 1){
        return false;
    }

    vector<int> check(27, 0);
    for(int i = 0; i < input.size(); i++){
        check[input[i] - 'A']++;
    }

    int count = 0;
    for(int i = 0; i < compare.size(); i++){
        if(abs(compare[i] - check[i]) > 1) return false;
        if(compare[i] != check[i]) {
            count++;
        }
    }

    return count <= 2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> input(n);
    vector<int> compare(27, 0);

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    for(int i = 0; i < input[0].size(); i++){
        compare[input[0][i] - 'A']++;
    }

    int count = 0;
    for(int i = 1; i < n; i++){
        if(Calculate(compare, input[i], input[0].size())) count++;
    }

    cout << count;

    return 0;
}