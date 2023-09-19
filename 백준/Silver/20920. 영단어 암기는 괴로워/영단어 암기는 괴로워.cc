#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//중복 없이 key-value 데이터 -> Map
//내림차순 정렬

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2){
    if(p1.second != p2.second)
        return p1.second > p2. second;
    if(p1.first.size() != p2.first.size())
        return p1.first.size() > p2.first.size();
    return p1.first < p2.first;
}

int main(){

    int n, length;
    string input;
    map<string, int> words;
    vector<pair<string, int>> temp;

    cin >> n >> length;

    while(n--){
        cin >> input;
        if(input.size() >= length){
            words[input]++;
        }
    }

    for(auto& it : words){
        temp.emplace_back(it);
    }

    sort(temp.begin(), temp.end(), cmp);

    for(auto word : temp){
        cout << word.first << '\n';
    }

    return 0;
}