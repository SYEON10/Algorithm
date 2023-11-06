#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.second < p2.second;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> title(n);
    vector<pair<int, int>> attack(m); //인덱스, 값
    vector<string> printTitle(m);

    for(auto &t : title){
        cin >> t.first >> t.second;
    }

    for(int i = 0; i < m; i++){
        cin >> attack[i].second;
        attack[i].first = i;
    }

    sort(attack.begin(), attack.end(), cmp);

    int beforeBound = 0, presentBound = 0;
    for(auto &t : title){
        presentBound = upper_bound(attack.begin(), attack.end(), make_pair(0, t.second), cmp) - attack.begin();
        for(int i = beforeBound; i < presentBound; i++){
            printTitle[attack[i].first] = t.first;
        }
        beforeBound = presentBound;
    }

    for(auto &print : printTitle){
        cout << print << '\n';
    }

    return 0;
}