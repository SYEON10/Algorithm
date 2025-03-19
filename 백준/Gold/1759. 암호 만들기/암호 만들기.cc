#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<char> table;
vector<bool> check;
vector<int> crypto;
unordered_map<char, bool> isVowels{
    {'a', true},
    {'e', true},
    {'i', true},
    {'o', true},
    {'u', true}
};
int l, c;
int vowels = 0, consonants = 0;

void print(){
    if(vowels < 1 || consonants < 2) return;
    for(int i = 1; i <= c ; i++){
        cout << table[crypto[i]];
    }
    cout << '\n';
}

void BackTracking(int index){
    if(index == c){
        print();
        return;
    }

    for(int num = 0; num < l; num++){
        if(crypto[index] > num || check[num]){
            continue;
        }
        if(isVowels[table[num]]) vowels++;
        else consonants++;
        crypto[index + 1] = num;
        check[num] = true;
        BackTracking(index + 1);
        check[num] = false;
        if(isVowels[table[num]]) vowels--;
        else consonants--;
    }
}

int main()
{
    cin >> c >> l;

    table.assign(l, 0);
    crypto.assign(c + 1, 0);
    check.assign(l, false);

    for(int i = 0; i < l; i++){
        cin >> table[i];
    }

    sort(table.begin(), table.end());

    BackTracking(0);

    return 0;
}