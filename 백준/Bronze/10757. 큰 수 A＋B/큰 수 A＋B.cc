#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> result;
    string a, b;

    cin >> a >> b;

    if(a.size() < b.size())
        swap(a, b);

    for(const auto &c : a)
        result.push_back(c - '0');

    for(int i = a.size() - b.size(), j = 0; i < a.size(); i++, j++){
        result[i] += (b[j] - '0');
    }

    for(int i = int(result.size()) - 1; i > 0; i--){
        if(result[i] >= 10){
            result[i - 1]++;
            result[i] %= 10;
        }
    }

    for(const auto &c : result)
        cout << c;

    return 0;
}