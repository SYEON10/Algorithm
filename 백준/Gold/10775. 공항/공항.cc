#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int SIZE = 1e5 + 1;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int g, p;
    cin >> g >> p;

    set<int> s;
    vector<int> gi(p);

    for(int i = 1; i <= g; i++){
        s.insert(i);
    }

    int count = 0;

    for(int i = 0; i < p; i++){
        cin >> gi[i];
    }

    for(int i : gi){
        auto it = s.upper_bound(i);
        if(it == s.begin()){
            break;
        }
        s.erase(--it);
        count++;
    }

    cout << count;

    return 0;
}